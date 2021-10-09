#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<pair<int, int>> c;
  vector<pair<int, int>> d;
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= b[i]) {
      c.emplace_back(a[i], b[i]);
    } else {
      d.emplace_back(b[i], a[i]);
    }
    s.push_back(a[i]);
    s.push_back(b[i]);
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  auto id = [&] (int v) -> int {
    return lower_bound(s.begin(), s.end(), v) - s.begin();
  };
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += abs(a[i] - b[i]);
  }
  int m = s.size();
  auto solve = [&] (vector<pair<int, int>> c, vector<pair<int, int>> d) {
    int mx = 0;
    vector<int> mn(m, inf);
    for (auto [l, r] : c) {
      mn[id(r)] = min(mn[id(r)], l);
    }
    for (int i = m - 2; i >= 0; --i) {
      mn[i] = min(mn[i], mn[i + 1]);
    }
    for (auto [l, r] : d) {
      int p = max(l, mn[id(r)]); 
      mx = max(mx, r - p);
    }
    return mx;
  };
  cout << sum - 2 * max(solve(c, d), solve(d, c)) << '\n';
}
