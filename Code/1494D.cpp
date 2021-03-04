#include <bits/stdc++.h>
using namespace std;
class dsu {
  private:
    vector<int> dat;
    int components_;
  public:
    dsu() {}
    explicit dsu(int n) : dat(n, -1), components_(n) {}
    
    int size() {
        return dat.size();
    }
    int root(int x) {
        assert(0 <= x), assert(x < size());
        return dat[x] < 0 ? x : dat[x] = root(dat[x]);
    }
    pair<int, int> unite(int x, int y) {
        assert(0 <= x), assert(x < size());
        assert(0 <= y), assert(y < size());
        x = root(x), y = root(y);
        if (x == y) {
            return { x, -1 };
        }
        components_ --;
        if (-dat[x] < -dat[y]) {
            swap(x, y);
        }
        dat[x] += dat[y];
        dat[y] = x;
        return { x, y };
    }
    bool same(int x, int y) {
        assert(0 <= x), assert(x < size());
        assert(0 <= y), assert(y < size());
        return root(x) == root(y);
    }
    int size(int x) {
        assert(0 <= x), assert(x < size());
        return -dat[root(x)];
    }
    int components() {
        return components_;
    }
};
int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int> (n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  int M = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      M = max(M, a[i][j]);
    }
  }
  vector<vector<pair<int, int> > > P(M + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        P[a[i][j]].emplace_back(i, j);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    ans.push_back(a[i][i]);
  }
  vector<pair<int, int> > edge;
  dsu dsu(n);
  int cur = n;
  vector<int> par(n);
  vector<int> last(n);
  iota(par.begin(), par.end(), 0);
  iota(last.begin(), last.end(), 0);
  for (int i = 1; i <= M; ++i) {
    vector<int> nd;
    vector<vector<int> > adj(n);
    for (auto [x, y] : P[i]) {
      nd.push_back(x);
      nd.push_back(y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    sort(nd.begin(), nd.end());
    nd.erase(unique(nd.begin(), nd.end()), nd.end());
    vector<bool> vis(n);
    for (int x : nd) {
      if (!vis[dsu.root(x)]) {
        vis[dsu.root(x)] = true;
        edge.emplace_back(par[dsu.root(x)], cur);
        par[dsu.root(x)] = cur ++;
        ans.push_back(i);
        for (int y : adj[x]) {
          vis[dsu.root(y)] = true;
          if (!dsu.same(x, y)) {
            x = dsu.root(x);
            y = dsu.root(y);
            edge.emplace_back(par[y], par[x]);
            par[y] = par[x];
            dsu.unite(x, y);
          }
        }
      } 
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  sort(edge.begin(), edge.end());
  edge.erase(unique(edge.begin(), edge.end()), edge.end());
  cout << par[dsu.root(0)] + 1 << '\n';
  for (auto [x, y] : edge) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
  return 0;
}
