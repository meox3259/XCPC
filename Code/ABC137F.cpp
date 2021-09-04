#include <bits/stdc++.h>
using namespace std;
long long modpow(long long x, long long y, int mod) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}
long long modinv(long long n, int mod) {
  return modpow(n, mod - 2, mod);
}
int main() {
  int p;
  cin >> p;
  vector<vector<long long>> binom(p + 1, vector<long long> (p + 1));
  binom[0][0] = 1;
  for (int i = 1; i <= p; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % p;
    }
  }
  vector<int> a(p);
  for (int i = 0; i < p; ++i) {
    cin >> a[i];
  }
  vector<long long> coef(p);
  for (int i = 0; i < p; ++i) {
    if (a[i] == 1) {
      coef[0] ++;
      coef[0] %= p;
      for (int j = 0; j < p; ++j) {
        coef[j] -= modpow(p - i, p - 1 - j, p) * binom[p - 1][j];
        coef[j] %= p;
        coef[j] += p;
        coef[j] %= p;
      }
    }
  }
  for (int i = 0; i < p; ++i) {
    cout << coef[i] << " \n"[i == p - 1];
  }
}
