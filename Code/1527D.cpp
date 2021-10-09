#include <bits/stdc++.h>
using namespace std;
class lowest_common_ancestor {
  const int LOG = 20;
  vector<int> d;
  vector<vector<int>> jump;
 public:
  lowest_common_ancestor(vector<vector<int>> adj, int Root = 0) {
    int N = adj.size();
    d = vector<int> (N, -1);
    d[Root] = 0;
    queue<int> q;
    q.push(Root);
    vector<int> p(N, -1);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : adj[x]) {
        if (d[y] == -1) {
          d[y] = d[x] + 1;
          p[y] = x;
          q.push(y);
        }
      }
    }   
    jump = vector<vector<int> > (LOG, vector<int> (N, -1));
    for (int i = 0; i < N; ++i) {
      jump[0][i] = p[i];
    }
    for (int i = 1; i < LOG; ++i) {
      for (int j = 0; j < N; ++j) {
        if (jump[i - 1][j] != -1) {
          jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
      }
    }
  }
  int up(int x, int d) {
    for (int i = 0; i < LOG; ++i) {
      if (d >> i & 1) {
        if (jump[i][x] == -1) {
          return -1;
        }
        x = jump[i][x];
      }
    }
    return x;
  }
  int lca(int x, int y) {
    if (d[x] > d[y]) {
      swap(x, y);
    }
    y = up(y, d[y] - d[x]);
    if (x == y) {
      return x;
    }
    for (int i = LOG - 1; i >= 0; --i) {
      if (jump[i][x] != jump[i][y]) {
        x = jump[i][x];
        y = jump[i][y];
      }
    }
    return jump[0][x];
  }
  int dis(int x, int y) {
    return d[x] + d[y] - 2 * d[lca(x, y)];
  }
};
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
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<int> sz(n, 1);
    auto dfs = [&] (auto &&f, int x, int par) -> void {
      for (int y : adj[x]) {
        if (y != par) {
          f(f, y, x);
          sz[x] += sz[y];
        }
      }
    };
    dfs(dfs, 0, -1);
    lowest_common_ancestor lca(adj);
    vector<long long> ans(n + 1);
    ans[0] = 1ll * n * (n - 1) / 2;
    ans[1] = ans[0];
    for (int i : adj[0]) {
      ans[1] -= 1ll * sz[i] * (sz[i] - 1) / 2; 
    }
    int p1 = 0;
    int p2 = 0;
    for (int i = 1; i < n; ++i) {
      int d1 = lca.dis(p1, p2);
      int d2 = lca.dis(p1, i);
      int d3 = lca.dis(p2, i);
      if (d1 + d2 == d3) {
        p1 = i;
      } else if (d1 + d3 == d2) {
        p2 = i;
      } else if (d1 != d2 + d3) {
        break;
      }
      int d = lca.dis(p1, p2);
      if (lca.up(p1, d) == p2) {
        int v = lca.up(p1, d - 1); 
        ans[i + 1] = 1ll * sz[p1] * (n - sz[v]);
      } else if (lca.up(p2, d) == p1) {
        int v = lca.up(p2, d - 1);
        ans[i + 1] = 1ll * sz[p2] * (n - sz[v]);
      } else {
        ans[i + 1] = 1ll * sz[p1] * sz[p2];
      }
    }
    for (int i = 0; i < n; ++i) {
      ans[i] -= ans[i + 1];
    }
    for (int i = 0; i <= n; ++i) {
      cout << ans[i] << " \n"[i == n];
    }
  }
}
