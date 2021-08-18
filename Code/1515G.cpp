#include <bits/stdc++.h>
using namespace std;
class scc {
  vector<vector<int>> adj;
  vector<vector<int>> rev;
  vector<int> scc_;
  vector<int> vs;
  vector<bool> vis;
  int n;
  int components_;
 public:
  scc() {}
  scc(int _n) : n(_n), scc_(_n), adj(_n), rev(_n), vis(_n), components_(0) {}
  void add_edge(int x, int y) {
    adj[x].push_back(y);
    rev[y].push_back(x);
  }
  void build() {
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        dfs(i);
      }
    }
    vis.assign(n, false);
    reverse(vs.begin(), vs.end());
    for (int i : vs) {
      if (!vis[i]) {
        dfs(i, components_++);
      }
    }
  }
  void dfs(int x) {
    vis[x] = true;
    for (int y : adj[x]) {
      if (!vis[y]) {
        dfs(y);
      }
    }
    vs.push_back(x);
  }
  void dfs(int x, int cnt) {
    vis[x] = true;
    scc_[x] = cnt;
    for (int y : rev[x]) {
      if (!vis[y]) {
        dfs(y, cnt);
      }
    }
  }
  int operator [] (int x) {
    return scc_[x];
  }
  int components() {
    return components_;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  scc scc(n);
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    x --;
    y --;
    scc.add_edge(x, y);
    adj[x].emplace_back(y, w);
  }
  scc.build();
  int k = scc.components();
  vector<long long> g(k);
  vector<long long> dis(n, -1);
  auto dfs = [&] (auto &&f, int x) -> void {
    for (auto [y, w] : adj[x]) {
      if (scc[x] == scc[y]) {
        if (dis[y] == -1) {
          dis[y] = dis[x] + w;
          f(f, y);
        } else {
          g[scc[x]] = __gcd(g[scc[x]], abs(dis[x] - dis[y] + w));   
        }
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (dis[i] == -1) {
      dis[i] = 0;
      dfs(dfs, i);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int v, s, t;
    cin >> v >> s >> t;
    v--;
    if (s % __gcd((long long)t, g[scc[v]]) == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
