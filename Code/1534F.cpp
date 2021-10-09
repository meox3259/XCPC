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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> b(m);
  vector<vector<int>> id(n, vector<int> (m));
  int k = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') {
        id[i][j] = k++;
        b[j].push_back(i);
      }
    }
  }
  scc scc(k);
  vector<vector<int>> adj(k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '#') {
        if (i > 0 && s[i - 1][j] == '#') {
          adj[id[i][j]].push_back(id[i - 1][j]);
          scc.add_edge(id[i][j], id[i - 1][j]);
        }
        if (j > 0) {
          auto it = lower_bound(b[j - 1].begin(), b[j - 1].end(), i);
          if (it != b[j - 1].end()) {
            scc.add_edge(id[i][j], id[*it][j - 1]);
            adj[id[i][j]].push_back(id[*it][j - 1]);
          }
        }
        if (j < m - 1) {
          auto it = lower_bound(b[j + 1].begin(), b[j + 1].end(), i);
          if (it != b[j + 1].end()) {
            scc.add_edge(id[i][j], id[*it][j + 1]);
            adj[id[i][j]].push_back(id[*it][j + 1]);
          }
        }
        auto it = upper_bound(b[j].begin(), b[j].end(), i);
        if (it != b[j].end()) {
          scc.add_edge(id[i][j], id[*it][j]);
          adj[id[i][j]].push_back(id[*it][j]);
        }
      }
    }
  }
  scc.build();
  int l = scc.components();
  vector<int> d(l);
  for (int i = 0; i < k; ++i) {
    for (int j : adj[i]) {
      if (scc[i] != scc[j]) {
        d[scc[j]]++;
      }
    }
  }
  cout << count(d.begin(), d.end(), 0) << '\n';
}
