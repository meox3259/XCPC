#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y, C;
    cin >> X >> Y >> C;
    X --;
    Y --;
    adj[Y].emplace_back(X, C);
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q; 
  Q.emplace(0, N - 1, 0);
  Q.emplace(0, N - 1, 1);
  vector<vector<int>> dp(N, vector<int> (2, Inf));
  dp[N - 1][0] = 0;
  dp[N - 1][1] = 0;
  while (!Q.empty()) {
    auto [D, X, i] = Q.top();
    Q.pop();
    if (D > dp[X][i]) {
      continue;
    }
    for (auto [Y, W] : adj[X]) {
      int tmp = max(dp[X][0], dp[X][1]);
      if (dp[Y][W] > tmp + 1) {
        dp[Y][W] = tmp + 1; 
        Q.emplace(dp[Y][W], Y, W);
      } 
    }
  }
  if (max(dp[0][0], dp[0][1]) == Inf) {
    cout << -1 << '\n';
  } else {
    cout << max(dp[0][0], dp[0][1]) << '\n';
  }
  string Ans(N, '1');
  for (int i = 0; i < N; ++i) {
    if (dp[i][0] > dp[i][1]) {
      Ans[i] = '0';
    }
  }
  cout << Ans << '\n';
}
