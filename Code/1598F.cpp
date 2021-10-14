#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<int> sum(1 << n);
  for (int i = 0; i < n; ++i) {
    int tot = 0;
    for (char c : s[i]) {
      tot += (c == '(' ? 1 : -1);
    }
    for (int S = 0; S < 1 << n; ++S) {
      if (S >> i & 1) {
        sum[S] += tot;
      }
    }
  }
  vector<vector<int>> pre(n);
  vector<vector<int>> mn(n);
  for (int i = 0; i < n; ++i) {
    pre[i].resize(s[i].size() + 1);
    mn[i].resize(s[i].size() + 1);
    for (int j = 0; j < s[i].size(); ++j) {
      pre[i][j + 1] = pre[i][j] + (s[i][j] == '(' ? 1 : -1);
    }
    mn[i][0] = numeric_limits<int>::max() / 2;
    for (int j = 1; j <= s[i].size(); ++j) {
      mn[i][j] = min(mn[i][j - 1], pre[i][j]);
    }
  }
  int L = 400000;
  vector<vector<int>> all(n);
  for (int i = 0; i < n; ++i) {
    all[i].resize(L + s[i].size() + 1);
    for (int j = 1; j <= s[i].size(); ++j) {
      if (mn[i][j] == pre[i][j]) {
        all[i][pre[i][j] + L]++;
      }
    }
  }
  vector<int> dp(1 << n, -L);
  dp[0] = 0;
  int ans = 0;
  for (int S = 0; S < 1 << n; ++S) {
    for (int i = 0; i < n; ++i) {
      if (!(S >> i & 1)) {
        if (sum[S] < 0) {
          continue;
        }
        int ndp = dp[S] + all[i][-sum[S] + L];
        ans = max(ans, ndp);
        if (sum[S] + mn[i].back() >= 0) {
          dp[S ^ (1 << i)] = max(dp[S ^ (1 << i)], ndp);
        }
      }
    } 
  }
  cout << ans << '\n';
}
