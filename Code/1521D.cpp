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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      x --;
      y --;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int leaf = 0;
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() == 1) {
        leaf = i;
      }
    }
    vector<tuple<int, int, int, int>> ans;
    auto dfs = [&] (auto &&f, int x, int p) -> int {
      int ch = 0;
      int ret = x;
      for (int y : adj[x]) {
        if (y != p) {
          int z = f(f, y, x);
          if (z == -1) {
            continue;
          }
          ch ++;
          if (ch == 1) {
            ret = z;  
          } else if (ch == 2) {
            ans.emplace_back(x, p, z, leaf);
            leaf = ret;
          } else {
            ans.emplace_back(y, x, y, leaf);
            leaf = z;
          }
        }
      }
      return (ch <= 1 ? ret : -1);
    }; 
    dfs(dfs, leaf, -1);
    cout << ans.size() << '\n';
    for (auto [a, b, c, d] : ans) {
      cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
    }
  }
}
