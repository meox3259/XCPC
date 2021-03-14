#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<char> op(N);
  for (int i = 0; i < N - 1; ++i) {
    cin >> A[i] >> op[i]; 
  }
  cin >> A[N - 1];
  vector<vector<long long>> dp(N + 1, vector<long long> (3, -Inf));
  dp[1][0] = A[0];
  for (int i = 1; i < N; ++i) {
    if (op[i - 1] == '+') {
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + A[i]);
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] - A[i]);
      dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + A[i]);
    } else {
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] - A[i]); 
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + A[i]);
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + A[i]);
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] - A[i]);
      dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + A[i]);
      dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + A[i]);
    }
  }
  cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
  return 0;
}
