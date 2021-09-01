#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
  vector<int> c(n);
  auto dfs = [&] (auto &&f, int x, int par) -> void {
    for (int y : adj[x]) {
      if (y != par) {
        c[y] = c[x] ^ 1;
        f(f, y, x);
      }
    }
  };
  dfs(dfs, 0, -1);
  vector<vector<int>> p(2);
  for (int i = 0; i < n; ++i) {
    p[c[i]].push_back(i);
  }
  if (p[0].size() < p[1].size()) {
    swap(p[0], p[1]);
  }
  vector<vector<int>> id(3);
  for (int i = 0; i < n; ++i) {
    id[i % 3].push_back(i);
  }
  vector<int> ans(n);
  if (p[0].size() >= id[0].size() && p[1].size() >= id[1].size()) {
    for (int i : id[0]) {
      ans[p[0].back()] = i;
      p[0].pop_back();
    }
    for (int i : id[1]) {
      ans[p[1].back()] = i;
      p[1].pop_back();
    }
  } else {
    for (int i : id[0]) {
      ans[p[0].back()] = i;
      p[0].pop_back();
    }
    for (int i : id[1]) {
      ans[p[0].back()] = i;
      p[0].pop_back();
    }
  }
  for (int i : id[2]) {
    if (!p[0].empty()) {
      ans[p[0].back()] = i;
      p[0].pop_back();
    } else {
      ans[p[1].back()] = i;
      p[1].pop_back();
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " \n"[i == n - 1];
  }
}
