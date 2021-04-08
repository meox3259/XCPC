#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, L;
  cin >> N >> M >> L;
  vector<int> K(N);
  for (int i = 0; i < N; ++i) {
    cin >> K[i];
    K[i] --;
  }
  vector<int> S(M);
  for (int i = 0; i < M; ++i) {
    cin >> S[i];
  }
  vector<long long> pre(M + 1);
  for (int i = 0; i < M; ++i) {
    pre[i + 1] = pre[i] + S[i];
  }
  sort(K.begin(), K.end());
  vector<vector<long long>> dp(N + 1, vector<long long> (N + 1, Inf));
  dp[1][1] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (pre[K[i] + 1] - pre[K[i - 1]]) / L);  
      dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + (pre[K[i] + 1] - pre[K[j - 1]]) / L);
    }   
  }
  long long Ans = Inf;
  for (int i = 0; i < N; ++i) {
    Ans = min(Ans, dp[N][i + 1] + (pre[K[N - 1] + 1] - pre[K[i]]) / L);
  }
  cout << Ans << '\n';
}
