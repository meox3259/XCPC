#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int n, m; 
  cin >> n >> m;
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<long long> ans(m + 1);
  for (int d = 1; d <= m; ++d) {
    vector<vector<long long>> dp(n + 1, vector<long long> (m / d + 1));
    vector<long long> pre(m / d + 1);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int nl = (l[i] + d - 1) / d;
      int nr = r[i] / d;
      assert(nl > 0);
      if (nl > nr) {
        continue;
      }
      pre[0] = dp[i][0];
      for (int j = 1; j <= m / d; ++j) {
        pre[j] = (pre[j - 1] + dp[i][j]) % mod; 
      } 
      for (int j = nl; j <= m / d; ++j) {
        dp[i + 1][j] += pre[j - nl]; 
        dp[i + 1][j] += mod - (j - nr - 1 >= 0 ? pre[j - nr - 1] : 0);
        dp[i + 1][j] %= mod;
      }
    } 
    ans[d] = accumulate(dp[n].begin(), dp[n].end(), 0ll) % mod;
  }
  for (int i = m; i >= 1; --i) {
    for (int j = i + i; j <= m; j += i) {
      ans[i] += mod - ans[j];
      ans[i] %= mod;
    }
  }
  cout << ans[1] << '\n';
}
