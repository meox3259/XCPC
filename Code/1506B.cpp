#include <bits/stdc++.h>
using namespace std;
const int Inf = numeric_limits<int> :: max() / 2;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> P;
    for (int i = 0; i < N; ++i) {
      if (S[i] == '*') {
        P.push_back(i);
      }
    }
    int M = P.size();
    vector<int> dp(M, Inf);
    dp[0] = 1;
    for (int i = 0; i < M; ++i) {
      for (int j = i + 1; j < M; ++j) {
        if (P[j] - P[i] <= K) {
          dp[j] = min(dp[j], dp[i] + 1);
        }
      } 
    }
    cout << dp[M - 1] << '\n';
  }
}
