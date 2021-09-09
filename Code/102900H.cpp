#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
      cin >> b[i];
    }
    sort(b.begin(), b.end());
    long long ans = inf;
    for (int d = 0; d < k; ++d) {
      vector<long long> c(k);
      for (int i = 0; i < k; ++i) {
        c[i] = (a[(i + d) % k] - b[i] + n) % n;
      }
      sort(c.begin(), c.end());
      ans = min(ans, c[k - 1]);
      ans = min(ans, n - c[0]);
      for (int i = 0; i < k - 1; ++i) {
        ans = min(ans, 2ll * c[i] + n - c[i + 1]);
        ans = min(ans, 2ll * (n - c[i + 1]) + c[i]);
      }
    }
    cout << ans << '\n';
  }
}
