#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] --;
  }
  vector<int> cnt(M + 1);
  for (int i : A) {
    cnt[i] ++; 
  }
  vector<vector<vector<int>>> dp(M + 1, vector<vector<int>> (3, vector<int> (3, -INF)));
  dp[0][0][0] = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (dp[i][j][k] >= 0) {
          for (int t = 0; t < 3; ++t) {
            if (cnt[i] - j - k - t >= 0) {
              dp[i + 1][k][t] = max(dp[i + 1][k][t], dp[i][j][k] + j + (cnt[i] - j - k - t) / 3);
            }
          } 
        }
      }
    }
  }
  cout << dp[M][0][0] << '\n';
}
