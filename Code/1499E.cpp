#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  string X, Y;
  cin >> X >> Y;
  int N = X.size();
  int M = Y.size();
  vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>> (M + 1, vector<long long> (27)));
  dp[0][0][0] = 1;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      dp[i][j][0] = 1;
      for (int k = 0; k < 27; ++k) {
        if (i < N) {
          int A = X[i] - 'a' + 1;
          if (k != A) {
            dp[i + 1][j][A] += dp[i][j][k];
            dp[i + 1][j][A] %= P;
          }
        }
        if (j < M) {
          int B = Y[j] - 'a' + 1;
          if (k != B) {
            dp[i][j + 1][B] += dp[i][j][k];
            dp[i][j + 1][B] %= P;
          }
        }
      }
    }
  }
  long long Ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      for (int k = 1; k < 27; ++k) {
        Ans += dp[i][j][k];
        Ans %= P;
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int k = 1; k < 27; ++k) {
      Ans -= dp[i][0][k] * M % P;
      Ans += P;
      Ans %= P;
    }
  }
  for (int i = 1; i <= M; ++i) {
    for (int k = 1; k < 27; ++k) {
      Ans -= dp[0][i][k] * N % P;
      Ans += P;
      Ans %= P;
    }
  }
  cout << Ans << '\n';
}
