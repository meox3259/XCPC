#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max() / 2;
int dp[85][85][85 * 85];
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      b.push_back(i + 1);
    }
  }
  if (b.empty()) {
    for (int i = 0; i <= n * (n - 1) / 2; ++i) {
      cout << 0 << " \n"[i == n * (n - 1) / 2];
    }
    exit(0);
  }
  int m = b.size();
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k <= n * (n - 1) / 2; ++k) {
        for (int l = j + 1; l <= n; ++l) {
          if (k + abs(l - b[i]) <= n * (n - 1) / 2) {
            dp[i + 1][l][k + abs(l - b[i])] = min(dp[i + 1][l][k + abs(l - b[i])], dp[i][j][k] + (l - j - 1) * (l - j - 2) / 2); 
          } 
        } 
      }  
    } 
  }
  vector<int> ans(n * (n - 1) / 2 + 1, inf);
  for (int i = 0; i <= n * (n - 1) / 2; ++i) {
    for (int j = 0; j <= n; ++j) {
      ans[i] = min(ans[i], dp[m][j][i] + (n - j) * (n - 1 - j) / 2);
    } 
    if (i >= 1) {
      ans[i] = min(ans[i], ans[i - 1]);
    }
  }
  for (int i = 0; i <= n * (n - 1) / 2; ++i) {
    cout << (n - m) * (n - m - 1) / 2 - ans[i] << " \n"[i == n * (n - 1) / 2];
  }
}
