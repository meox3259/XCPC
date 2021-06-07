#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<vector<int>> V(N, vector<int> (2));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 2; ++j) {
        cin >> V[i][j];
      }
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      adj[X].push_back(Y);
      adj[Y].push_back(X);
    }
    vector<vector<long long>> dp(N, vector<long long> (2));
    auto dfs = [&] (auto &&f, int X, int F) -> void {
      for (int Y : adj[X]) {
        if (Y != F) {
          f(f, Y, X);
          for (int i = 0; i < 2; ++i) {
            dp[X][i] += max(dp[Y][0] + abs(V[X][i] - V[Y][0]), dp[Y][1] + abs(V[X][i] - V[Y][1]));
          }
        }
      }
    };
    dfs(dfs, 0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
  }
}
