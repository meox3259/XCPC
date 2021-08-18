#include <bits/stdc++.h>
using namespace std;
const long long inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<long long> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<long long> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  long long g = 0;
  for (int i = 0; i < n - 1; ++i) {
    g = __gcd(g, x[i + 1] - x[i]);
  }
  vector<pair<long long, long long>> ans;
  for (int i = 0; i < m; ++i) {
    if (g % p[i] == 0) {
      ans.emplace_back((x[0] % p[i] == 0 ? p[i] : x[0] % p[i]), i);
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.empty()) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    cout << ans[0].first << ' ' << ans[0].second + 1 << '\n';
  }
}
