#include <bits/stdc++.h>
using namespace std;
long long power(long long X, long long Y, long long M) {
  long long ret = 1;
  for (; Y; Y >>= 1, X = X * X % M) {
    if (Y & 1) {
      ret = ret * X % M;
    }
  }
  return ret;
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> i2(N + 1);
  i2[0] = 1;
  for (int i = 0; i < N; ++i) {
    i2[i + 1] = i2[i] * 2 % M;
  }
  vector<long long> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fac[i] = fac[i - 1] * i % M;
  }
  vector<long long> inv(N + 1);
  for (int i = 0; i <= N; ++i) {
    inv[i] = power(fac[i], M - 2, M);
  }
  vector<vector<long long>> f(N + 1, vector<long long> (N + 1));
  f[0][0] = 1;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      if (i < N) {
        f[i + 1][j] += f[i][j];
        f[i + 1][j] %= M;
      }
      if (j < N) {
        f[i][j + 1] += f[i][j];
        f[i][j + 1] %= M;
      }
    }
  }
  vector<long long> tot(N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < i; ++j) {
      tot[i] += f[j][i - j - 1];
      tot[i] %= M;
    } 
  }
  vector<vector<vector<long long>>> dp(2, vector<vector<long long>> (N + 1, vector<long long> (N + 1)));
  dp[1][1][1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= i + 1; ++j) {
      for (int k = 0; k <= i + 1; ++k) {
        dp[(i & 1) ^ 1][j][k] = 0;
      }
    }
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= i; ++k) {
        dp[(i & 1) ^ 1][j][0] += dp[i & 1][j][k] * tot[k] % M * inv[k] % M;
      }
      dp[(i & 1) ^ 1][j][0] %= M;
      dp[(i & 1) ^ 1][j + 1][1] += dp[i & 1][j][0] * (j + 1);
      dp[(i & 1) ^ 1][j + 1][1] %= M;
      for (int k = 1; k <= i; ++k) {
        dp[(i & 1) ^ 1][j + 1][k + 1] += dp[i & 1][j][k] * (j + 1);
        dp[(i & 1) ^ 1][j + 1][k + 1] %= M;
      }
    }
  }
  long long Ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      long long V = dp[N & 1][i][j] * tot[j] % M * inv[j] % M;
      Ans += V;
      Ans %= M;
    }
  }
  cout << Ans << '\n';
}
