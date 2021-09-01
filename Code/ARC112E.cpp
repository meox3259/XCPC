#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] --;
  }
  vector<vector<long long>> dp(m + 1, vector<long long> (n + 1)); 
  dp[0][0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i + 1][j] += dp[i][j] * j * 2;
      dp[i + 1][j] %= mod;
      if (j < n) {
        dp[i + 1][j + 1] += dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
    }
  }
  vector<vector<long long>> binom(n + 1, vector<long long> (n + 1));
  binom[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod; 
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans +=  dp[m][i + n - 1 - j] * binom[i + n - 1 - j][i];
      ans %= mod;
      if (j != n - 1 && a[j] > a[j + 1]) {
        break;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    ans += dp[m][n] * binom[n][i];
    ans %= mod;
  }
  cout << ans << '\n';
}
