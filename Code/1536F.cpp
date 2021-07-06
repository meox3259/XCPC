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
  int N;
  cin >> N;
  vector<long long> fac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  vector<long long> inv(N + 1);
  inv[N] = power(fac[N], P - 2);
  for (int i = N; i >= 1; --i) {
    inv[i - 1] = inv[i] * i % P;
  }
  auto C = [&] (int N, int M) -> long long {
    if (N < 0 || M < 0) {
      return 0LL;
    }
    if (N < M) {
      return 0LL;
    }
    return fac[N] * inv[M] % P * inv[N - M] % P;
  };
  long long Ans = 0;
  for (int i = 2; i <= N; i += 2) {
    Ans += (C(i, N - i) + C(i - 1, N - i - 1)) * 2 * fac[i];
    Ans %= P;
  }
  cout << Ans << '\n';
}
