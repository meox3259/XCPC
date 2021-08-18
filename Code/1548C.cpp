#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
long long power(long long X, long long Y) {
  long long ret = 1;
  for (; Y; Y >>= 1, X = X * X % P) {
    if (Y & 1) {
      ret = ret * X % P;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<long long > fac(3 * N + 2);
  fac[0] = 1;
  for (int i = 1; i <= 3 * N + 1; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  vector<long long> inv(3 * N + 2);
  inv[3 * N + 1] = power(fac[3 * N + 1], P - 2);
  for (int i = 3 * N + 1; i >= 1; --i) {
    inv[i - 1] = inv[i] * i % P;
  }
  auto C = [&] (int N, int M) -> long long {
    if (N < M) {
      return 0;
    }
    return fac[N] * inv[N - M] % P * inv[M] % P;
  };
  vector<vector<long long>> dp(3 * N + 1, vector<long long> (3));
  for (int i = 1; i <= 3 * N; ++i) {
    dp[0][i % 3] ++;
  }
  long long i3 = power(3, P - 2);
  for(int i = 1; i <= 3 * N; ++i) {
    dp[i][0] = (C(3 * N, i + 1) - dp[i - 1][0] * 2 - dp[i - 1][1]) * i3;
    dp[i][0] %= P;
    dp[i][0] += P;
    dp[i][0] %= P;
    dp[i][1] = dp[i - 1][0] + dp[i][0];
    dp[i][1] %= P;
    dp[i][2] = dp[i - 1][1] + dp[i][1];
    dp[i][2] %= P;
  }
  while (Q --> 0) {
    int X;
    cin >> X;
    cout << (dp[X][0] + C(3 * N, X)) % P << '\n';
  }
}
