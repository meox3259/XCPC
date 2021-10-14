#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<bool> vis(n);
    vector<int> dep(n);
    vector<int> par(n, -1);
    auto dfs = [&] (auto &&dfs, int x) -> void {
      vis[x] = true;
      for (int y : adj[x]) {
        if (!vis[y]) {
          dep[y] = dep[x] + 1;
          par[y] = x;
          dfs(dfs, y);
        }
      }
    };
    dfs(dfs, 0);
    int x = max_element(dep.begin(), dep.end()) - dep.begin();
    if (dep[x] + 1 >= (n + 1) / 2) {
      vector<int> ans;
      while (x != -1) {
        ans.push_back(x);
        x = par[x];
      }
      cout << "PATH\n";
      cout << ans.size() << '\n';
      for (int i : ans) {
        cout << i + 1 << " \n"[i == ans.back()];
      }
    } else {
      vector<vector<int>> node(n);
      for (int i = 0; i < n; ++i) {
        node[dep[i]].push_back(i);
      }
      vector<pair<int, int>> ans;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < node[i].size(); j += 2) {
          ans.emplace_back(node[i][j], node[i][j + 1]);
        } 
      }
      cout << "PAIRING\n";
      cout << ans.size() << '\n';
      for (auto [x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
      }
    }
  }
}
