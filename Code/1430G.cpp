#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  vector<int> y(m);
  vector<int> w(m);
  vector<int> out(1 << n);
  vector<int> a(1 << n);
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i] >> w[i];
    x[i]--;
    y[i]--;
    out[1 << x[i]] |= 1 << y[i];
    a[1 << x[i]] += w[i];
    a[1 << y[i]] -= w[i];
  }
  for (int S = 0; S < 1 << n; ++S) {
    out[S] = out[S ^ (S & -S)] | out[S & -S];
    a[S] = a[S ^ (S & -S)] + a[S & -S];
  }
  vector<int> dp(1 << n, inf);
  vector<int> pre(1 << n);
  vector<int> d(1 << n);
  dp[0] = 0;
  for (int S = 0; S < 1 << n; ++S) {
    for (int T = S; T; T = (T - 1) & S) {
      if (!(T & out[T]) && !(T & out[S ^ T])) {
        if (dp[S] > dp[S ^ T] + a[((1 << n) - 1) ^ S]) {
          dp[S] = dp[S ^ T] + a[((1 << n) - 1) ^ S];
          pre[S] = S ^ T;
          d[S] = d[S ^ T] + 1;
        }
      }
    } 
  }
  vector<int> ans(n);
  for (int S = (1 << n) - 1; S; S = pre[S]) {
    for (int i = 0; i < n; ++i) {
      if (S >> i & 1) {
        ans[i] = d[S];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] - 1 << " \n"[i == n - 1];
  }
}
