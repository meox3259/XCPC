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
vector<int> GetPrime(int n) {
  vector<bool> mark(n + 1);
  vector<int> Prime;
  vector<int> phi(n + 1);
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!mark[i]) {
      Prime.emplace_back(i);
      phi[i] = i - 1;
    }
    for (int j = 0; j < Prime.size() && i * Prime[j] <= n; ++j) {
      mark[i * Prime[j]] = true;
      if (i % Prime[j] == 0) {
        phi[i * Prime[j]] = phi[i] * Prime[j];
        break;
      }
      phi[i * Prime[j]] = phi[i] * (Prime[j] - 1);
    }
  }
  return phi;
}
int main() {
  auto phi = GetPrime(1000000);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    k = min(k, n);
    vector<long long> i2(n + 1);
    i2[0] = 1;
    for (int i = 1; i <= n; ++i) {
      i2[i] = i2[i - 1] * 2 % mod;
    }
    long long ans = 0;
    auto coef = [&] (int n, int m) -> long long {
      if (m == 0) {
        if (n % 2 == 0) {
          return 2;
        } else {
          return 0;
        }
      }
      return i2[m] * (binom(n - m, m) + binom(n - m - 1, m - 1)) % mod;
    };
    auto calc = [&] (int d) -> long long {
      int m = 1ll * k * d / n; 
      long long ret = 0;
      for (int i = 0; i <= m; ++i) {
        ret += coef(d, i);
      }
      return ret % mod;
    };
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        ans += 1ll * phi[n / i] * calc(i);
        if (i * i != n) {
          ans += 1ll * phi[i] * calc(n / i); 
        }
        ans %= mod;
      }
    }
    ans %= mod;
    ans *= inv(n);
    ans %= mod;
    cout << ans << '\n';
  }
}
