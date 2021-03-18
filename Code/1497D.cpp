#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int N;
    cin >> N;
    vector<int> tag(N);
    for (int i = 0; i < N; ++i) {
      cin >> tag[i];
    }
    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    vector<long long> dp(N); 
    for (int i = 1; i < N; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (tag[i] != tag[j]) {
          long long dpi = dp[i];
          long long dpj = dp[j];
          dp[i] = max(dp[i], dpj + abs(S[i] - S[j]));
          dp[j] = max(dp[j], dpi + abs(S[i] - S[j]));
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
