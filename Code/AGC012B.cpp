#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  int Q;
  cin >> Q;
  vector<int> V(Q);
  vector<int> D(Q);
  vector<int> C(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> V[i] >> D[i] >> C[i];
  }
  for (int i = 0; i < Q; ++i) {
    V[i] --;
    C[i] --;
  }
  vector<vector<int>> S(N, vector<int> (11, -1));
  for (int i = 0; i < Q; ++i) {
    S[V[i]][D[i]] = i;
  }
  vector<vector<int>> dp(N, vector<int> (11, -1));
  vector<int> Ans(N, -1);
  for (int i = 0; i <= 10; ++i) {
    for (int X = 0; X < N; ++X) {
      dp[X][i] = S[X][i];
    }
    for (int j = 0; j < i; ++j) {
      for (int X = 0; X < N; ++X) {
        for (int Y : adj[X]) {
          dp[Y][i] = max(dp[Y][i], S[X][i]); 
        }
      }
      for (int X = 0; X < N; ++X) {
        S[X][i] = dp[X][i];
      }
    } 
  }
  for (int X = 0; X < N; ++X) {
    for (int i = 0; i <= 10; ++i) {
      Ans[X] = max(Ans[X], dp[X][i]);
    } 
  }
  for (int i = 0; i < N; ++i) {
    cout << (Ans[i] == -1 ? 0 : C[Ans[i]] + 1) << '\n';
  }
}
