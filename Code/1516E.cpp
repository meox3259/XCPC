#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long modpow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}
long long modinv(long long n) {
  return modpow(n, mod - 2);
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> binom(m * 2 + 1, vector<long long> (m * 2 + 1));
  binom[0][0] = 1;
  for (int i = 1; i <= m * 2; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
    }
  }
  vector<vector<long long>> f(m * 2 + 1, vector<long long> (m + 1));
  f[0][0] = 1;
  for (int i = 1; i <= m * 2; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= m; ++j) {
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (i - 1)) % mod;
    } 
  }
  vector<vector<long long>> g(m * 2 + 1, vector<long long> (m + 1));
  for (int i = 1; i <= m * 2; ++i) {
    g[i][0] = 1;
    for (int j = 1; j <= m; ++j) {
      for (int k = i; k >= 0; --k) {
        if ((i - k) % 2 == 0) {
          g[i][j] += f[k][j] * binom[i][k];
          g[i][j] %= mod;
          g[i][j] += mod;
          g[i][j] %= mod;
        } else {
          g[i][j] -= f[k][j] * binom[i][k]; 
          g[i][j] %= mod;
          g[i][j] += mod;
          g[i][j] %= mod;
        }
      } 
    }
  }
  vector<long long> inv(m * 2 + 1);
  for (int i = 1; i <= m * 2; ++i) {
    inv[i] = modinv(i);
  }
  vector<long long> dp(m * 2 + 1, -1);
  auto choose = [&] (int n, int m) -> long long {
    if (n < m) {
      return 0;
    }
    if (dp[m] != -1) {
      return dp[m];
    }
    dp[m] = 1;
    for (int i = n - m + 1; i <= n; ++i) {
      dp[m] *= i;
      dp[m] %= mod;
    }
    for (int i = 1; i <= m; ++i) {
      dp[m] *= inv[i];
      dp[m] %= mod;
    }
    return dp[m];
  };
  for (int i = 1; i <= m; ++i) {
    long long ans = 0;
    for (int j = i; j >= 1; j -= 2) {
      for (int k = 0; k <= min(n, m * 2); ++k) {
        ans += g[k][j] * choose(n, k);
        ans %= mod;
      }
    }
    if (i % 2 == 0) {
      ans ++;
      ans %= mod;
    }
    cout << ans << " \n"[i == m];
  }
}
