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
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<pair<int, int>> op;
    for (int i = 0; i < n / 2; ++i) {
      op.emplace_back(i, n - 1);
      swap(p[i], p[n - 1]);
    }
    for (int i = n / 2; i < n - 1; ++i) {
      op.emplace_back(i, 0);
      swap(p[i], p[0]);
    }
    reverse(op.begin(), op.end());
    long long ans = 0;
    for (auto [a, b] : op) {
      ans += 1ll * (a - b) * (a - b);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
      cout << p[i] + 1 << " \n"[i == n - 1];
    }
    cout << op.size() << '\n';
    for (auto [a, b] : op) {
      cout << a + 1 << ' ' << b + 1 << '\n';
    }
  }
}
