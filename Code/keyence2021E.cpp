#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
  }
  vector<vector<vector<int>>> dp(N + 5, vector<vector<int>> (N + 5, vector<int> (N + 5, -1)));
  auto dfs = [&] (auto &&f, int l, int r, int k) -> int {
    if (dp[l][r][k] != -1) {
      return dp[l][r][k];
    }
    if (l == 0 && r == N + 1) {
      return dp[l][r][k] = 0;
    }
    if (r == N + 1 || a[l] > a[r]) {
      dp[l][r][k] = f(f, l - 1, r, k + 1);
    } else {
      dp[l][r][k] = f(f, l, r + 1, k + 1);
    }
    if (k >= 1) {
      if (l >= 1) {
        dp[l][r][k] = max(dp[l][r][k], f(f, l - 1, r, k - 1) + a[l]);
      }
      if (r <= N) {
        dp[l][r][k] = max(dp[l][r][k], f(f, l, r + 1, k - 1) + a[r]);
      }
    }
    return dp[l][r][k];
  };
  for (int i = 0; i <= N; ++i) {
    cout << dfs(dfs, i, i + 1, 1) << '\n';
  }
  return 0;
}
