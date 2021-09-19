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
      adj[y].push_back(x);
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      for (int j : adj[i]) {
        if (c[j] == 1) {
          c[i] = 2;
          break;
        } 
        if (c[j] == 0) {
          c[i] = 1; 
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (c[i] == 2) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << '\n';
    for (int i : ans) {
      cout << i + 1 << " \n"[i == ans.back()];
    }
  }
}
