#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int> :: max() / 2;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&] (int i, int j) {
    return v[i] > v[j];
  });
  vector<int> x(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
  }
  while (q --) {
    int l, r;
    cin >> l >> r;
    l --;
    r --;
    int ans = 0;
    vector<bool> vis(m);
    for (int i = l; i <= r; ++i) {
      vis[i] = true;
    }
    for (int i = 0; i < n; ++i) {
      int Min = inf;
      for (int j = 0; j < m; ++j) {
        if (!vis[j] && x[j] >= w[id[i]]) {
          Min = min(Min, x[j]); 
        }
      }
      for (int j = 0; j < m; ++j) {
        if (!vis[j] && x[j] == Min) {
          vis[j] = true;
          ans += v[id[i]];
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
