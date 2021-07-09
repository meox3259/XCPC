#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
class LowestCommonAncestor {
  const int LOG = 20;
  vector<int> d;
  vector<vector<int> > jump;
 public:
  LowestCommonAncestor(vector<vector<int> > adj, int Root) {
    int N = adj.size();
    d = vector<int> (N, -1);
    d[Root] = 0;
    queue<int> q;
    q.push(Root);
    vector<int> p(N, -1);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : adj[x]) {
        if (d[y] == -1) {
          d[y] = d[x] + 1;
          p[y] = x;
          q.push(y);
        }
      }
    }   
    jump = vector<vector<int> > (LOG, vector<int> (N, -1));
    for (int i = 0; i < N; ++i) {
      jump[0][i] = p[i];
    }
    for (int i = 1; i < LOG; ++i) {
      for (int j = 0; j < N; ++j) {
        if (jump[i - 1][j] != -1) {
          jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
      }
    }
  }
  int up(int x, int d) {
    for (int i = 0; i < LOG; ++i) {
      if (d >> i & 1){
        x = jump[i][x];
      }
    }
    return x;
  }
  int lca(int x, int y) {
    if (d[x] > d[y]) {
      swap(x, y);
    }
    y = up(y, d[y] - d[x]);
    if (x == y) {
      return x;
    }
    for (int i = LOG - 1; i >= 0; --i) {
      if (jump[i][x] != jump[i][y]) {
        x = jump[i][x];
        y = jump[i][y];
      }
    }
    return jump[0][x];
  }
};
long long power(long long X, long long T) {
  long long ret = 1;
  for (; T; T >>= 1, X = X * X % P) {
    if (T & 1) {
      ret = ret * X % P;
    }
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }  
  long long inv2 = power(2, P - 2);
  vector<vector<long long>> dp(N + 1, vector<long long> (N + 1));
  for (int i = 1; i <= N; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv2;
      dp[i][j] %= P;
    }
  }
  vector<vector<long long>> Sum(N + 1, vector<long long> (N + 1));
  for (int i = 0; i <= N; ++i) {
    Sum[i][0] = dp[i][0];
    for (int j = 1; j <= N; ++j) {
      Sum[i][j] = Sum[i][j - 1] + dp[i][j];
      Sum[i][j] %= P;
    }
  }
  long long Ans = 0;
  for (int S = 0; S < N; ++S) {
    vector<int> dep(N);
    long long cur = 0;
    auto dfs = [&] (auto &&f, int X, int F) -> void {
      for (int Y : adj[X]) {
        if (Y != F) {
          dep[Y] = dep[X] + 1;
          f(f, Y, X);
        }
      } 
    }; 
    dfs(dfs, S, -1);
    LowestCommonAncestor LCA(adj, S);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        int k = LCA.lca(i, j);
        cur += dp[dep[i] - dep[k]][dep[j] - dep[k]];  
        cur %= P;
      } 
    }
    cur *= power(N, P - 2);
    cur %= P;
    Ans += cur;
    Ans %= P;
  }
  cout << Ans << '\n';
}
