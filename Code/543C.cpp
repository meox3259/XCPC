#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  vector<vector<int>> A(N, vector<int> (M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> ST(N, vector<int> (M));
  vector<vector<int>> Sum(N, vector<int> (M));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      int Max = 0;
      for (int k = 0; k < N; ++k) {
        if (S[k][i] == S[j][i]) {
          ST[j][i] |= 1 << k; 
          Sum[j][i] += A[k][i];
          Max = max(Max, A[k][i]);
        }
      }
      Sum[j][i] -= Max;
    }
  }
  vector<int> dp(1 << N, Inf);
  dp[0] = 0;
  for (int S = 0; S < 1 << N; ++S) {
    int P = -1; 
    for (int i = N - 1; i >= 0; --i) {
      if (!(S >> i & 1)) {
        P = i;
      }
    }
    if (P != -1) {
      for (int i = 0; i < M; ++i) {
        dp[S | (1 << P)] = min(dp[S | (1 << P)], dp[S] + A[P][i]);
        dp[S | ST[P][i]] = min(dp[S | ST[P][i]], dp[S] + Sum[P][i]);
      }
    }
  }
  cout << dp.back() << '\n';
}
