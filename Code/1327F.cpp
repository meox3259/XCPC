#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> l(m);
  vector<int> r(m);
  vector<int> x(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i] >> x[i]; 
    l[i] --;
    r[i] --;
  }
  long long ans = 1;
  for (int j = 0; j < k; ++j) {
    vector<int> add(n + 2);
    vector<vector<int>> left(n + 1);
    for (int i = 0; i < m; ++i) {
      if (x[i] >> j & 1) {
        add[l[i]] ++;
        add[r[i] + 1] --;
      } else {
        left[r[i]].push_back(l[i]);
      }
    }
    for (int i = 0; i < n; ++i) {
      add[i + 1] += add[i];
    }
    vector<long long> dp(n + 2);
    int bound = -1;
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {
      if (i != n) {
        dp[i + 1] = dp[i];
      }
      if (!add[i]) {
        dp[i + 1] += dp[i] - (bound == -1 ? 0 : dp[bound]);
        dp[i + 1] %= mod;
        dp[i + 1] += mod;
        dp[i + 1] %= mod;
      }
      for (int k : left[i]) {
        bound = max(bound, k);
      }
    }
    ans *= dp[n + 1];
    ans %= mod;
  }
  cout << ans << '\n';
}
