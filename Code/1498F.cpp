#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n, vector<int> (k * 2));
  auto dfs = [&] (auto &&f, int x, int par) -> void {
    dp[x][0] = a[x];
    for (int y : adj[x]) {
      if (y != par) {
        f(f, y, x);
        for (int j = 0; j < k * 2; ++j) {
          dp[x][(j + 1) % (k * 2)] ^= dp[y][j];
        }  
      }
    }
  };
  dfs(dfs, 0, -1);
  vector<int> ans(n);
  auto dfs1 = [&] (auto &&f, int x, int par) -> void {
    for (int i = k; i < k * 2; ++i) {
      ans[x] ^= dp[x][i];
    } 
    vector<int> tmp(k * 2);
    for (int y : adj[x]) {
      if (y != par) {
        for (int j = 0; j < k * 2; ++j) {
          tmp[(j + 1) % (k * 2)] = dp[x][(j + 1) % (k * 2)] ^ dp[y][j];
        } 
        for (int j = 0; j < k * 2; ++j) {
          dp[y][(j + 1) % (k * 2)] ^= tmp[j];
        }
        f(f, y, x);
      } 
    }
  };
  dfs1(dfs1, 0, -1);
  for (int i = 0; i < n; ++i) {
    cout << (ans[i] ? 1 : 0) << " \n"[i == n - 1];
  }
}
