#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, W;
  cin >> N >> W;
  vector<int> w(N);
  for (int i = 0; i < N; ++i) {
    cin >> w[i];
  }
  sort(w.begin(), w.end(), greater<int> ());
  vector<vector<int>> dp(N + 1, vector<int> (W + 1));
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= P;
      if (j + w[i] <= W) {
        dp[i + 1][j + w[i]] += dp[i][j];
        dp[i + 1][j + w[i]] %= P;
      }
    }
  }
  int Ans = 0;
  for (int i = 0; i <= W; ++i) {
    int d = W - i;
    int j = N - 1;
    int S = 0;
    while (j >= 0 && w[j] <= d) {
      S += w[j];
      j --; 
    }
    if (S <= i) {
      Ans += dp[j + 1][i - S];
      Ans %= P;
    }
  }
  cout << Ans << '\n';
}
