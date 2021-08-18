#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;
long long power(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}
int main() {
  auto query = [&] (int x) -> int {
    cout << '?' << ' ' << x << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  vector<vector<long long>> g(12, vector<long long> (12)); 
  for (int i = 0; i < 11; ++i) {
    g[i][11] = query(i);
    long long coef = 1;
    for (int j = 0; j < 11; ++j) {
      g[i][j] = coef;
      coef *= i;
      coef %= mod;
    }
  }
  for (int j = 0; j < 11; ++j) {
    int P = -1; 
    for (int i = j; i < 11; ++i) {
      if (g[i][j] > 0) {
        P = i; 
        break;
      }
    }
    if (P == -1) {
      continue;
    }
    swap(g[j], g[P]);
    long long v = g[j][j];
    long long inv = power(v, mod - 2);
    for (int i = 0; i < 12; ++i) {
      g[j][i] *= inv;
      g[j][i] %= mod;
    }
    for (int i = 0; i < 11; ++i) {
      if (j != i) {
        long long tmp = g[i][j];
        for (int k = 0; k < 12; ++k) {
          g[i][k] -= g[j][k] * tmp;
          g[i][k] %= mod;
          g[i][k] += mod;
          g[i][k] %= mod;
        }
      } 
    }
  }
  vector<long long> a(11);
  for (int i = 0; i < 11; ++i) {
    a[i] = g[i][11];
  }
  int ans = -1;
  for (int i = 0; i < mod; ++i) {
    long long s = 0;
    long long p = 1;
    for(int j = 0; j < 11; ++j) {
      s += p * a[j];
      s %= mod;
      s += mod;
      s %= mod;
      p *= i;
      p %= mod;
    }
    if (s == 0) {
      ans = i;
    }
  }
  cout << '!' << ' ' << ans << endl;
}
