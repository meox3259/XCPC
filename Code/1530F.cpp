#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int MOD = 31607;
const int M = 21;
int A[M][M];
int tmp[M][1 << M];
int f[1 << M];
int f0[1 << M];
int f1[1 << M];
int f01[1 << M];
int g[1 << M];
void fwt(int *f, int rev, int n) {
  for(int i = 1; i < n; i <<= 1) {
    for(int p = i << 1, j = 0; j < n; j += p) {
      for(int k = 0; k < i; k++) {
        f[j + k] = f[j + k] + rev * f[i + j + k];
        if (f[j + k] < 0) {
          f[j + k] += MOD;
        } else if (f[j + k] >= MOD) {
          f[j + k] -= MOD;
        }
      }
    }
  }
}
int power(int X, int Y) {
  int ret = 1;
  for (; Y; Y >>= 1, X = X * X % MOD) {
    if (Y & 1) {
      ret = ret * X % MOD;
    }
  }
  return ret;
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  int INV = power(10000, MOD - 2);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      A[i][j] *= INV;
      A[i][j] %= MOD;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int S = 0; S < 1 << N; ++S) {
      tmp[i][S] = 1;
      for (int j = 0; j < N; ++j) {
        if (S >> j & 1) {
          tmp[i][S] *= A[i][j];
          tmp[i][S] %= MOD;
        } else {
          tmp[i][S] *= (MOD + 1 - A[i][j]);
          tmp[i][S] %= MOD;
        }
      }
    }
  }
  int Ans = 0;
  for (int i = 0; i < 1 << N; ++i) {
    g[i] = 1;
  }
  for (int i = 0; i < N; ++i) {
    memset(f, 0, sizeof(f));
    for (int S = 0; S < (1 << N) - 1; ++S) {
      f[S] = tmp[i][S];
    }
    fwt(f, 1, 1 << N);
    for (int j = 0; j < 1 << N; ++j) {
      g[j] *= f[j];
      g[j] %= MOD;
    }
  }
  fwt(g, -1, 1 << N);
  Ans += g[0];
  for (int i = 0; i < 1 << N; ++i) {
    g[i] = 1;
  }
  for (int i = 0; i < N; ++i) {
    memset(f0, 0, sizeof(f0));
    for (int S = 0; S < (1 << N) - 1; ++S) {
      if (S >> i & 1) {
        f0[S] = tmp[i][S];
      } 
    }
    fwt(f0, 1, 1 << N);
    for (int j = 0; j < 1 << N; ++j) {
      g[j] *= f0[j];
      g[j] %= MOD;
    }
  }
  fwt(g, -1, 1 << N);
  Ans -= g[0];
  for (int i = 0; i < 1 << N; ++i) {
    g[i] = 1;
  }
  for (int i = 0; i < N; ++i) {
    memset(f1, 0, sizeof(f1));
    for (int S = 0; S < (1 << N) - 1; ++S) {
      if (S >> (N - 1 - i) & 1) {
        f1[S] = tmp[i][S];
      }
    }
    fwt(f1, 1, 1 << N);
    for (int j = 0; j < 1 << N; ++j) {
      g[j] *= f1[j];
      g[j] %= MOD;
    }
  }
  fwt(g, -1, 1 << N);
  Ans -= g[0];
  for (int i = 0; i < 1 << N; ++i) {
    g[i] = 1;
  }
  for (int i = 0; i < N; ++i) {
    memset(f01, 0, sizeof(f01));
    for (int S = 0; S < (1 << N) - 1; ++S) {
      if ((S >> i & 1) && (S >> (N - 1 - i) & 1)) {
        f01[S] = tmp[i][S];
      }
    }
    fwt(f01, 1, 1 << N);
    for (int j = 0; j < 1 << N; ++j) {
      g[j] *= f01[j];
      g[j] %= MOD;
    }
  }
  fwt(g, -1, 1 << N);
  Ans += g[0];
  Ans %= MOD;
  Ans += MOD;
  Ans %= MOD;
  cout << (MOD + 1 - Ans) % MOD << '\n';
}
