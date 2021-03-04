#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K, P;
  cin >> N >> K >> P;
  vector<vector<int>> dp(N + 1, vector<int> (N * (N + 1) / 2 * K + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= i * (i + 1) / 2 * K; ++j) {
      dp[i][j] = dp[i - 1][j];  
      if (j >= i) {
        dp[i][j] += dp[i][j - i];
        dp[i][j] %= P;
      }
    }
    for (int j = i * (i + 1) / 2 * K; j >= (K + 1) * i; --j) {
      dp[i][j] -= dp[i][j - (K + 1) * i];
      dp[i][j] += P;
      dp[i][j] %= P;
    }
  }
  for (int X = 1; X <= N; ++X) {
    int ans = 0; 
    for (int i = 0; i <= N * (N + 1) / 2 * K; ++i) {
      ans += 1LL * dp[X - 1][i] * dp[N - X][i] % P;
      ans %= P;
    }
    ans = 1LL * ans * (K + 1) % P;
    ans -= 1;
    ans += P;
    ans %= P;
    cout << ans << '\n';
  }
  return 0;
}
