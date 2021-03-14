#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long t) {
  long long ret = 1;
  for (; t; t >>= 1, x = x * x % 7) {
    if (t & 1) {
      ret = ret * x % 7;
    }
  }
  return ret;
} 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  vector<vector<int>> dp(N + 1, vector<int> (7));
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    int b = power(10, i) * (S[i] - '0') % 7;
    for (int j = 0; j < 7; ++j) {
      if (T[i] == 'A') {
        if (!dp[i][(j - b + 7) % 7] || !dp[i][j]) {
          dp[i + 1][j] = 0;
        } else {
          dp[i + 1][j] = 1;
        }
      } else {
        if (dp[i][(j - b + 7) % 7] || dp[i][j]) {
          dp[i + 1][j] = 1;
        } 
      }
    } 
  }
  if (dp[N][0]) {
    cout << "Takahashi" << '\n';
  } else {
    cout << "Aoki" << '\n';
  }
  return 0;
}
