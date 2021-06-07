#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
  auto bfs = [&] (int S) -> int {
    vector<int> d(N, -1);
    queue<int> Q;
    Q.push(S);
    d[S] = 0;
    while (!Q.empty()) {
      int X = Q.front();
      Q.pop();
      for (int Y : adj[X]) {
        if (d[Y] == -1) {
          d[Y] = d[X] + 1;
          Q.push(Y);
        }
      }
    }
    return max_element(d.begin(), d.end()) - d.begin();
  };
  int B = bfs(0);
  int T = bfs(B);
  vector<int> dep(N);
  vector<int> Maxdep(N);
  auto pre = [&] (auto &&f, int X, int F) -> void {
    Maxdep[X] = dep[X];
    for (int Y : adj[X]) {
      if (Y != F) {
        dep[Y] = dep[X] + 1;
        f(f, Y, X); 
        Maxdep[X] = max(Maxdep[X], Maxdep[Y]);
      }
    }
  };
  pre(pre, T, -1);
  vector<int> Ans(N);
  vector<int> Max(N);
  set<int> S;
  auto dfs = [&] (auto &&f, int X, int F) -> void {
    sort(adj[X].begin(), adj[X].end(), [&] (int i, int j) {
      return Maxdep[i] < Maxdep[j];
    });
    Ans[X] = dep[X];
    S.insert(Max[X] - 2 * dep[X]);
    for (int Y : adj[X]) {
      if (Y != F) {
        dep[Y] = dep[X] + 1;
        f(f, Y, X);
        assert(S.find(Max[X] - 2 * dep[X]) != S.end());
        S.erase(S.find(Max[X] - 2 * dep[X]));
        Max[X] = max(Max[X], Max[Y]);
        S.insert(Max[X] - 2 * dep[X]);
      }
    }
    assert(S.find(Max[X] - 2 * dep[X]) != S.end());
    S.erase(S.find(Max[X] - 2 * dep[X]));
    if (!S.empty()) {
      Ans[X] = dep[X] + *S.rbegin();
    }
    Max[X] = max(Max[X], Ans[X] + dep[X]);
  };
  dfs(dfs, T, -1);
  for (int i = 0; i < N; ++i) {
    cout << Ans[i] + 1 << " \n"[i == N - 1];
  }
}
