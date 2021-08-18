#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long power(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % P) {
    if (y & 1) {
      ret = ret * x % P;
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  vector<long long> inv(n + 1);
  for (int i = 1; i <= n; ++i) {
    inv[i] = power(i, P - 2);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> l(n + 1, n);
  for (int i = 0; i < n; ++i) {
    l[a[i]] = min(l[a[i]], i);
  }
  vector<int> cnt(n + 1);
  for (int i : a) {
    cnt[i] ++;
  }
  vector<vector<long long>> dp(n + 1, vector<long long> (n + 1));
  vector<vector<long long>> sum(n + 1, vector<long long> (n + 1));
  dp[0][0] = 1;
  sum[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j >= 1) {
        dp[i][j] += sum[l[a[i - 1]]][j - 1] * inv[n - j + 1];
        dp[i][j] %= P;
      }
      sum[i][j] += sum[i - 1][j];
      sum[i][j] += dp[i][j];
      sum[i][j] %= P;
    } 
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      ans += dp[i][j] * (cnt[a[i - 1]] - 1) % P * inv[n - j];
      ans %= P;
    }
  }
  cout << ans << '\n';
}
