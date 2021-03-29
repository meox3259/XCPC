#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  vector<vector<long long>> C(5001, vector<long long> (5001));
  C[0][0] = 1;
  for (int i = 1; i <= 5000; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
  }
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> dp(16, vector<long long> (M + 1));
  dp[0][0] = 1;
  for (int i = 0; i < 15; ++i) {
    int D = 1 << i; 
    for (int j = 0; j <= M; ++j) {
      for (int k = 0; k * D + j <= M && k <= N; k += 2) {
        dp[i + 1][j + k * D] += dp[i][j] * C[N][k] % P;
        dp[i + 1][j + k * D] %= P;
      }
    }
  }
  cout << dp[15][M] << '\n';
}
