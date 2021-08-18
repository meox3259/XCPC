#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long> (3));
  for (int i = 0; i < n; ++i) {
    dp[i + 1][0] = max(0ll, max(0ll, dp[i][0]) + a[i]);
    dp[i + 1][1] = max(max(dp[i][1], dp[i][0]) + a[i] * x, 0ll);
    dp[i + 1][2] = max(0ll, max(dp[i][2], dp[i][1]) + a[i]);
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
