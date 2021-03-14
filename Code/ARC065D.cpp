#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
  int N, M;
  string S;
  cin >> N >> M >> S;
  vector<int> L(M);
  vector<int> R(M);
  for (int i = 0; i < M; ++i) {
    cin >> L[i] >> R[i];
    L[i] --;
  }
  vector<int> F(N); 
  iota(F.begin(), F.end(), 1);
  for (int i = 0; i < M; ++i) {
    F[L[i]] = max(F[L[i]], R[i]);
  }
  for (int i = 0; i < N - 1; ++i) {
    F[i + 1] = max(F[i + 1], F[i]);
  }
  vector<int> Sum(N + 1);
  for (int i = 0; i < N; ++i) {
    Sum[i + 1] = Sum[i] + S[i] - '0';
  }
  vector<vector<int>> dp(N + 1, vector<int> (N + 1));
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= P;
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + 1] %= P;
    }
    int Max = min(Sum[F[i]], i + 1);
    int Min = max(0, Sum[F[i]] - F[i] + i + 1);
    for (int j = 0; j <= N; ++j) {
      if (j < Min || j > Max) {
        dp[i + 1][j] = 0;
      }
    }
  }
  cout << dp[N][Sum.back()] << '\n';
  return 0;
}
