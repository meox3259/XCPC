#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    char C;
    cin >> X >> Y >> C;
    X --;
    Y --;
    adj[X].emplace_back(Y, C - 'a');
    adj[Y].emplace_back(X, C - 'a');
  }
  vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (27, Inf)));
  queue<tuple<int, int, int>> Q;
  for (int i = 0; i < N; ++i) {
    for (auto [j, C] : adj[i]) {
      dp[i][j][26] = 1;
      dp[j][i][26] = 1;
      Q.emplace(i, j, 26);
      Q.emplace(j, i, 26);
    } 
  }
  for (int i = 0; i < N; ++i) {
    dp[i][i][26] = 0;
    Q.emplace(i, i, 26);
  }
  while (!Q.empty()) {
    auto [X, Y, C] = Q.front();
    Q.pop();
    if (C == 26) {
      for (auto [Z, W] : adj[Y]) {
        if (dp[X][Z][W] > dp[X][Y][C] + 1) {
          dp[X][Z][W] = dp[X][Y][C] + 1;
          Q.emplace(X, Z, W);
        } 
      }
    } else {
      for (auto [Z, W] : adj[X]) {
        if (W == C) {
          if (dp[Z][Y][26] > dp[X][Y][C] + 1) {
            dp[Z][Y][26] = dp[X][Y][C] + 1;
            Q.emplace(Z, Y, 26);
          }
        }
      }
    }
  }
  if (dp[0][N - 1][26] == Inf) {
    cout << -1 << '\n';
  } else {
    cout << dp[0][N - 1][26] << '\n';
  }
}
