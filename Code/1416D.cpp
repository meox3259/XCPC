#include <bits/stdc++.h>
using namespace std;
struct sgt {
  vector<int> mx;
  sgt() {}
  sgt(int n) : mx(n * 4 + 5, -1) {}
  void update(int l, int r, int x, int p, int v) {
    if (l == r) {
      mx[x] = v;
      return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
      update(l, mid, x << 1, p, v);
    } else {
      update(mid + 1, r, x << 1 | 1, p, v);
    }
    mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
  }
  int query(int l, int r, int x, int a, int b) {
    if (l > b || r < a) {
      return -1;
    }
    if (l >= a && r <= b) {
      return mx[x];
    }
    int mid = l + r >> 1;
    return max(query(l, mid, x << 1, a, b), query(mid + 1, r, x << 1 | 1, a, b));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  vector<pair<int, int>> e;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    e.emplace_back(x, y);
  }
  vector<pair<int, int>> ask(q);
  vector<bool> vis(m);
  for (int i = 0; i < q; ++i) {
    cin >> ask[i].first >> ask[i].second;
    ask[i].second--;
    if (ask[i].first == 2) {
      vis[ask[i].second] = true;
    }
  }
  vector<int> par(n + m + q);
  iota(par.begin(), par.end(), 0);
  auto find = [&] (auto &&find, int x) -> int {
    return x == par[x] ? x : par[x] = find(find, par[x]);
  };
  vector<int> t(n + m + q);
  vector<vector<int>> adj(n + m + q);
  int tot = n;
  for (int i = 0; i < m; ++i) {
    if (!vis[i]) {
      int x = find(find, e[i].first);
      int y = find(find, e[i].second);
      if (x != y) {
        t[tot] = q;
        adj[tot].push_back(x);
        adj[tot].push_back(y);
        par[x] = tot;
        par[y] = tot;
        tot++;
      }
    }
  }
  for (int i = q - 1; i >= 0; --i) {
    if (ask[i].first == 2) {
      int x = find(find, e[ask[i].second].first);
      int y = find(find, e[ask[i].second].second);
      if (x != y) {
        par[x] = tot;
        par[y] = tot;
        t[tot] = i;
        adj[tot].push_back(x);
        adj[tot].push_back(y);
        tot++;
      }
    } 
  }
  vector<int> dfn(tot, -1);
  vector<int> out(tot, -1);
  int dfc = 0;
  vector<vector<int>> jump(tot, vector<int> (21, -1));
  auto dfs = [&] (auto &&dfs, int x) -> void {
    dfn[x] = dfc++;
    for (int y : adj[x]) {
      jump[y][0] = x;
      dfs(dfs, y);
    }
    out[x] = dfc;
  };
  for (int i = 0; i < tot; ++i) {
    if (par[i] == i) {
      dfs(dfs, i);
    }
  }
  sgt sgt(tot);
  for (int i = 0; i < n; ++i) {
    sgt.update(0, tot - 1, 1, dfn[i], p[i]); 
  }
  for (int j = 0; j < 20; ++j) {
    for (int i = 0; i < tot; ++i) {
      if (jump[i][j] != -1) {
        jump[i][j + 1] = jump[jump[i][j]][j];
      }
    }
  }
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    id[p[i]] = i;
  }
  for (int i = 0; i < q; ++i) {
    if (ask[i].first == 1) {
      int x = ask[i].second;      
      for (int j = 20; j >= 0; --j) {
        if (jump[x][j] != -1 && t[jump[x][j]] >= i) {
          x = jump[x][j];
        }
      }
      int y = sgt.query(0, tot - 1, 1, dfn[x], out[x] - 1);
      cout << y + 1 << '\n';
      if (y != -1) {
        sgt.update(0, tot - 1, 1, dfn[id[y]], -1);
      }
    } 
  }
}
