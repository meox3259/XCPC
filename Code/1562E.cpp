#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> lcp(n, vector<int> (n));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        lcp[i][j] = (s[i] == s[j] ? ((i < n - 1 && j < n - 1) ? lcp[i + 1][j + 1] : 0) + 1 : 0);
      }
    }
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = n - i;
      for (int j = 0; j < i; ++j) {
        if (i + lcp[i][j] < n && s[j + lcp[i][j]] < s[i + lcp[i][j]]) {
          dp[i] = max(dp[i], dp[j] + (n - lcp[j][i] - i)); 
        }
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
}
