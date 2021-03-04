#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<unordered_set<int> > adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  vector<int> fib(30);
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < 30; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  int p = -1;
  for (int i = 0; i < 30; ++i) {
    if (fib[i] == n) {
      p = i;
    }
  }
  if (p == -1) {
    cout << "NO" << '\n';
    exit(0);
  }
  vector<int> dp(n);
  auto check = [&] (auto &&f, int N, int S, int k) -> bool {
    if (N <= 3) {
      return true;
    }
    int X = -1;
    int Y = -1;
    auto dfs = [&] (auto &&f, int x, int par) -> void {
      dp[x] = 1;
      for (int y : adj[x]) {
        if (y != par) {
          f(f, y, x);
          dp[x] += dp[y];
        }
      }
      if (dp[x] == fib[k - 1] || dp[x] == fib[k - 2]) {
        X = x;
        Y = par;
      }
    };
    dfs(dfs, S, -1);
    if (X == -1) {
      return false;
    }
    adj[X].erase(Y);
    adj[Y].erase(X);
    if (dp[X] == fib[k - 2]) {
      return f(f, dp[X], X, k - 2) && f(f, dp[S] - dp[X], Y, k - 1);
    } else {
      return f(f, dp[X], X, k - 1) && f(f, dp[S] - dp[X], Y, k - 2);
    }
  };
  if (check(check, n, 0, p)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
