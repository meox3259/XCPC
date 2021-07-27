
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int> (N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> A[i][j];
      }
    }
    vector<vector<int>> B(N, vector<int> (N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> B[i][j];
      }
    }
    vector<vector<vector<pair<int, int>>>> dp(N, vector<vector<pair<int, int>>> (N));
    dp[0][0].emplace_back(A[0][0], B[0][0]);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i != 0 || j != 0) {
          if (i == 0) {
            for (auto V : dp[i][j - 1]) {
              dp[i][j].push_back(V);
            }
          } else if (j == 0) {
            for (auto V : dp[i - 1][j]) {
              dp[i][j].push_back(V);
            }
          } else {
            int X = 0;
            int Y = 0;
            int Max = 0;
            while (X < dp[i - 1][j].size() && Y < dp[i][j - 1].size()) {
              if ((dp[i - 1][j][X].first > dp[i][j - 1][Y].first) || (dp[i - 1][j][X].first == dp[i][j - 1][Y].first &&
                   dp[i - 1][j][X].second > dp[i][j - 1][Y].second)) {
                if (dp[i - 1][j][X].second > Max) {
                  dp[i][j].push_back(dp[i - 1][j][X]);
                  Max = dp[i - 1][j][X].second;
                }
                X ++;
              } else {
                if (dp[i][j - 1][Y].second > Max) {
                  dp[i][j].push_back(dp[i][j - 1][Y]);
                  Max = dp[i][j - 1][Y].second;
                }
                Y ++;
              }
            }
            while (X < dp[i - 1][j].size()) {
              if (dp[i - 1][j][X].second > Max) {
                dp[i][j].push_back(dp[i - 1][j][X]);
                Max = dp[i - 1][j][X].second;
              }
              X ++;
            }
            while (Y < dp[i][j - 1].size()) {
              if (dp[i][j - 1][Y].second > Max) {
                dp[i][j].push_back(dp[i][j - 1][Y]);
                Max = dp[i][j - 1][Y].second;
              } 
              Y ++;
            }
          }
          for (auto &V : dp[i][j]) {
            V.first += A[i][j];
            V.second += B[i][j];
          }
        }
      }
    }
    long long Ans = 0;
    for (auto V : dp[N - 1][N - 1]) {
      Ans = max(Ans, 1LL * V.first * V.second);
    }
    cout << Ans << '\n';
  }
}
