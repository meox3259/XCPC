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
  vector<long long> fac(200001);
  fac[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    fac[i] = fac[i - 1] * i % P;
  }
  vector<long long> inv(200001);
  inv[200000] = power(fac[200000], P - 2);
  for (int i = 200000; i >= 1; --i) {
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
  int T;
  cin >> T;
  while (T --> 0) {
    int N, K;
    cin >> N >> K;
    long long Ans = 1;
    for (int i = 1; i <= N && (i - 1) * (K - 1) <= N; ++i) {
      Ans += C(N - (i - 1) * (K - 1), i) * inv[N] % P * fac[N - i] % P * fac[i] % P; 
      Ans %= P;
    }
    cout << Ans << '\n';
  }
}
