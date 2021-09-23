#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i]--;
    }
    vector<int> b;
    for (int i : a) {
      if (b.empty() || i != b.back()) {
        b.push_back(i);
      }
    }
    int m = b.size();
    vector<int> pre(m, -1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < i; ++j) {
        if (b[i] == b[j]) {
          pre[i] = j;
        }
      }
    }
    vector<vector<int>> dp(m, vector<int> (m));
    for (int l = 2; l <= m; ++l) {
      for (int i = 0; i + l - 1 < m; ++i) {
        int j = i + l - 1;
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        for (int k = pre[j]; k >= i; k = pre[k]) {
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j - 1] + 1); 
        }
      }
    }
    cout << m - 1 - dp[0][m - 1] << '\n';
  }
}
