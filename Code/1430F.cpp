#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  vector<int> r(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i] >> a[i];
  }
  vector<long long> dp(n);
  for (int i = n - 1; i >= 0; --i) {
    if (i < n - 1 && r[i] == l[i + 1]) {
      dp[i] = max(0ll, dp[i + 1] + a[i] - 1ll * (r[i] - l[i]) * k); 
    } else {
      dp[i] = max(0ll, a[i] - 1ll * (r[i] - l[i]) * k);
    }
    if (dp[i] > k) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  long long ans = 0;
  long long cur = k;
  for (int i = 0; i < n; ++i) {
    if (cur < dp[i]) {
      ans += cur;
      cur = k;
    } 
    ans += a[i];
    if (a[i] > cur) {
      cur = k - (a[i] - cur) % k;
    } else {
      cur -= a[i];
    }
  }
  cout << ans << '\n';
}
