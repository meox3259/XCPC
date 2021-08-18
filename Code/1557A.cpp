#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = 0.;
    for (int i = 0; i < n - 1; ++i) {
      ans += a[i];
    }
    ans /= (double)(n - 1);
    ans += a.back();
    cout << fixed << setprecision(10);
    cout << ans << '\n';
  }
}
