#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> t(k);
  for (int i = 0; i < k; ++i) {
    cin >> t[i];
  }
  vector<int> s;
  for (int i : a) {
    s.push_back(i);
  }
  for (int i : t) {
    s.push_back(i);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  int m = s.size();
  vector<int> cut(m);
  for (int i : a) {
    cut[lower_bound(s.begin(), s.end(), i) - s.begin()] ^= 1;
  }
  for (int i : t) {
    cut[lower_bound(s.begin(), s.end(), i) - s.begin()] ^= 1;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
  }
  vector<int> b;
  for (int i = 0; i < m; ++i) {
    if (cut[i]) {
      b.push_back(i);
    }
  }
  int sz = b.size();
  if (sz > n || (sz - n) % 2 != 0) {
    cout << -1 << '\n';
    exit(0);
  }
  vector<vector<long long>> dp(n + 1, vector<long long> (sz + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= sz; ++j) {
      if (i < n && j < sz) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(s[a[i]] - s[b[j]]));
      }
      if (i + 1 < n) {
        dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + s[a[i + 1]] - s[a[i]]);
      }
    }
  }
  cout << dp[n][sz] << '\n';
}
