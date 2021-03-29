#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
long long power(long long x, long long t) {
  long long ret = 1;
  for (; t; t >>= 1, x = x * x % P) {
    if (t & 1) {
      ret = ret * x % P;
    }
  }
  return ret;
}
int main() {
  int N, M;
  cin >> N >> M;
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
    return fac[N] * facinv[N - M] % P * facinv[M] % P;
  };
  vector<vector<long long>> dp(M + 1, vector<long long> (19));
  long long Ans = 1;
  for (int i = 2; i <= M; ++i) {
    dp[i][1] = 1;
  }
  for (int k = 1; k < 18; ++k) {
    for (int i = 2; i <= M; ++i) {
      for (int j = i + i; j <= M; j += i) {
        dp[j][k + 1] += dp[i][k];
        dp[j][k + 1] %= P;
      }
    } 
  }
  for (int k = 0; k <= 18; ++k) {
    long long S = 0;
    for (int i = 0; i <= M; ++i) {
      S += dp[i][k];
      S %= P;
    }
    Ans += C(N, k) * S % P;
    Ans %= P;
  }
  cout << Ans << '\n';
}
