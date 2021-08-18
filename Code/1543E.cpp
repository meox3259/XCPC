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
    vector<vector<int>> adj(1 << n);
    for (int i = 0; i < n * (1 << n - 1); ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<int> ans(1 << n);
    vector<int> bit(1 << n);
    vector<bool> vis(1 << n);
    vector<int> cur;
    vis[0] = true;
    for (int i = 0; i < n; ++i) {
      int j = adj[0][i]; 
      bit[j] = 1 << i;
      cur.push_back(j);
      vis[j] = true;
    }
    for (int i = 1; i < n; ++i) {
      for (int j : cur) {
        for (int k : adj[j]) {
          if (!vis[k]) {
            bit[k] |= bit[j]; 
          } 
        } 
      }
      vector<int> nxt;
      for (int j : cur) {
        for (int k : adj[j]) {
          if (!vis[k]) {
            vis[k] = true;
            nxt.push_back(k);
          }
        }
      }
      swap(cur, nxt);
    }
    for (int i = 0; i < 1 << n; ++i) {
      ans[bit[i]] = i;
    }
    for (int i = 0; i < 1 << n; ++i) {
      cout << ans[i] << " \n"[i + 1 == (1 << n)];
    }
    if (__builtin_popcount(n) > 1) {
      cout << -1 << '\n';
    } else {
      vector<int> color(1 << n);
      for (int i = 0; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i >> j & 1) {
            color[i] ^= j;
          }
        }
      }
      for (int i = 0; i < 1 << n; ++i) {
        cout << color[bit[i]] << " \n"[i + 1 == (1 << n)];
      }
    }
  }
}
