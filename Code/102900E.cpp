#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<long long> fac_ = {1};
vector<long long> inv_ = {1, 1};
vector<long long> facinv_ = {1, 1};
long long fac(int n) {
  for (int i = fac_.size(); i <= n; ++i) {
    fac_.push_back(fac_.back() * i % mod);
  }
  return fac_[n];
}
long long inv(int n) {
  for (int i = inv_.size(); i <= n; ++i) {
    inv_.push_back((mod - mod / i) * inv_[mod % i] % mod);
  }
  return inv_[n];
}
long long facinv(int n) {
  for (int i = facinv_.size(); i <= n; ++i) {
    facinv_.push_back(facinv_.back() * inv(i) % mod);
  }
  return facinv_[n];
}
long long binom(int n, int m) {
  if (n < 0 || m < 0 || m > n) {
    return 0;
  } else {
    return fac(n) * facinv(m) % mod * facinv(n - m) % mod;
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> dp(n + 1);
  vector<long long> s(n + 1);
  dp[0] = 1;
  s[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = (s[i - 1] - (i - k - 1 >= 0 ? s[i - k - 1] : 0) + mod) * fac(i - 1) % mod; 
    s[i] = (s[i - 1] + dp[i] * facinv(i)) % mod;
  }
  cout << dp[n] << '\n';
}
