#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<long long>> dp(N + 1, vector<long long> (2, -Inf));
  dp[1][0] = 0;
  dp[1][1] = 0;
  for (int i = 1; i < N; ++i) {
    if (A[i] > A[i - 1]) {
      dp[i + 1][1] = max(dp[i][0], dp[i][1] + A[i] - A[i - 1]);
      dp[i + 1][0] = max(dp[i][0], dp[i][1]);
    } else {
      dp[i + 1][0] = max(dp[i][1], dp[i][0] + A[i - 1] - A[i]);
      dp[i + 1][1] = max(dp[i][0], dp[i][1]);
    }
  }
  cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
}
