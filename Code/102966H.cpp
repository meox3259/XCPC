#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
long long power(long long X, long long T) {
  long long ret = 1;
  for (; T; T >>= 1, X = X * X % P) {
    if (T & 1) {
      ret = ret * X % P;
    }
  }
  return ret;
}
int main() {
  vector<long long> fac(200001);
  fac[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  vector<long long> facinv(200001);
  facinv[200000] = power(fac[200000], P - 2);
  for (int i = 200000; i >= 1; --i) {
    facinv[i - 1] = facinv[i] * i % P;
  }
  auto C = [&] (int N, int M) -> long long {
    if (N < M) {
      return 0LL;
    }
    return fac[N] * facinv[M] % P * facinv[N - M] % P;
  };
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    cout << C(N + N - 1, N - 1) << '\n';
  }
}
