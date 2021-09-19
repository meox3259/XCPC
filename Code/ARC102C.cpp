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
  int k, n;
  cin >> k >> n;
  vector<long long> i2(n + k + 1);
  i2[0] = 1;
  for (int i = 1; i <= n + k; ++i) {
    i2[i] = i2[i - 1] * 2 % mod;
  }
  auto calc = [&] (int x, int y, int z) -> long long {
    long long ret = 0;  
    for (int i = 0; i <= z && i <= x; ++i) {
      ret += binom(x, i) * i2[i] % mod * binom(z + y - 1, i + y - 1) % mod; 
    }
    ret %= mod;
    return ret;
  };
  for (int i = 2; i <= k * 2; ++i) {
    int cnt = 0;
    for (int j = 1; j <= k; ++j) {
      if (1 <= i - j && i - j <= k) {
        cnt++;
      }
    }    
    if (i % 2 == 1) {
      cout << calc(cnt / 2, k - cnt, n) << '\n';
    } else {
      cout << (calc((cnt - 1) / 2, k - cnt, n) + calc((cnt - 1) / 2, k - cnt, n - 1)) % mod << '\n';
    }
  }
}
