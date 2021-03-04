#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
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
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> B(A);
  sort(B.begin(), B.end());
  vector<long long> inv(N + 1);
  for (int i = 1; i <= N; ++i) {
    inv[i] = power(i, P - 2);
  }
  vector<int> rnk(N);
  iota(rnk.begin(), rnk.end(), 0);
  long long ans = 0;
  do {
    auto C = [&] (int n, int m) -> long long {
      if (n < m) {
        return 0LL;
      }
      long long ret = 1;
      for (int i = 1; i <= m; ++i) {
        ret = ret * (n - i + 1) % P;
      }
      for (int i = 1; i <= m; ++i) {
        ret = ret * inv[i] % P;
      }
      return ret;
    };
    vector<int> f(N);
    for (int i = 0; i < N; ++i) {
      f[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (rnk[j] < rnk[i]) {
          f[i] = max(f[i], f[j] + 1);
        }
      } 
    }
    int Max = *max_element(f.begin(), f.end());
    vector<vector<long long>> dp(N + 1, vector<long long> (N + 1));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
      int L = (i > 0 ? B[i - 1] : 0);
      int R = B[i];
      for (int j = 0; j <= N; ++j) {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= P;
      }
      for (int j = 0; j < N; ++j) {
        int tot = 0;
        for (int k = j + 1; k <= N; ++k) {
          if (A[rnk[k - 1]] <= L) {
            break;
          }
          if (k - j >= 2 && rnk[k - 1] < rnk[k - 2]) {
            tot ++; 
          }
          dp[i + 1][k] += dp[i][j] * C(R - L + tot, k - j) % P;
          dp[i + 1][k] %= P;
        }
      }
    }
    ans += dp[N][N] * Max;
    ans %= P;
  } while (next_permutation(rnk.begin(), rnk.end()));
  long long down = 1;
  for (int i : A) {
    down = down * power(i, P - 2) % P;
  }
  ans *= down;
  ans %= P;
  cout << ans << '\n';
  return 0;
}
