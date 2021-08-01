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
template <class T = int> class hld {
 private:
  class edge {
   public:
    int from, to;
    T w;
    int operator - (int x) const {
      return from ^ to ^ x;
    } 
  };
  int n;
  vector<edge> es;
  vector<vector<int>> adj;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
 public:
  hld(int _n = 0) : n(_n), adj(_n) {}
  void add(int x, int y, T w = 1) {
    adj[x].push_back(es.size()), adj[y].push_back(es.size());
    es.push_back({x, y, w});
  }
  void dfs(int x) {
    sz[x] = 1;
    for (int i : adj[x]) {
      if (i != pe[x]) {
        int y = es[i] - x;
        assert(pv[y] == -1);
        pv[y] = x, pe[y] = i;
        dep[y] = dep[x] + 1, dist[y] = dist[x] + es[i].w;
        dfs(y);
        sz[x] += sz[y];
      }
    }
    sort(adj[x].begin(), adj[x].end(), [&] (int i, int j) -> bool {
      return sz[es[i] - x] * (i != pe[x]) > sz[es[j] - x] * (j != pe[x]);
    }); 
  }
  void build(int root = 0) {
    assert((int)es.size() == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[root] = -1, dep[root] = 0, dist[root] = 0;
    dfs(root);
  }
  void dfs_hld(int x) {
    in[x] = vs.size();
    vs.push_back(x);
    for (int i : adj[x]) {
      if (i != pe[x]) {
        int y = es[i] - x; 
        head[y] = (y == es[adj[x][0]] - x ? head[x] : y);
        dfs_hld(y);
      }
    }
    out[x] = vs.size();
  }
  void build_hld(int root = 0) {
    build(root);
    vs.clear(), in.resize(n), out.resize(n), head.resize(n);
    head[root] = root;
    dfs_hld(root);
  }
  bool anc(int x, int y) const {
    return in[x] <= in[y] && out[y] <= out[x];
  }
  int lca(int x, int y) const {
    while (true) {
      if (in[x] > in[y]) {
        swap(x, y);
      }
      if (head[x] == head[y]) {
        return x;
      }
      y = pv[head[y]];
    } 
  }
  int d(int x, int y) const {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
  }
  T len(int x, int y) const {
    return dist[x] + dist[y] - 2 * dist[lca(x, y)]; 
  }
  vector<pair<int, int>> ascend(int from, int to) const {
    vector<pair<int, int>> res; 
    while (head[from] != head[to]) {
      res.emplace_back(in[from], in[head[from]]);
      from = pv[head[from]];
    }
    if (from != to) {
      res.emplace_back(in[from], in[to] + 1); 
    }
    return res;
  }
  vector<pair<int, int>> descend(int from, int to) const {
    if (from == to) {
      return {};
    }
    if (head[from] == head[to]) {
      return {{in[from] + 1, in[to]}};
    }
    auto res = descend(from, pv[head[to]]);
    res.emplace_back(in[head[to]], in[to]);
    return res;
  }
  template <class F> void run(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    for (auto e : ascend(from, v)) {
      f(e.first, e.second);
    }
    if (vertex) {
      f(in[v], in[v]);
    }
    for (auto e : descend(v, to)) {
      f(e.first, e.second);
    }
  }
  template <class F> int ask(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    int ret = 0;
    for (auto e : ascend(from, v)) {
      ret += f(e.first, e.second);
    }
    if (vertex) {
      ret += f(in[v], in[v]);
    }
    for (auto e : descend(v, to)) {
      ret += f(e.first, e.second);
    }
    return ret;
  }
};
class sgt {
  vector<int> sum;
  vector<int> tag;
 public:
  sgt() {}
  sgt(int N) : sum(N * 4), tag(N * 4) {}
  void pushdown(int X, int L, int R) {
    int Mid = L + R >> 1;
    sum[X << 1] += tag[X] * (Mid - L + 1);
    sum[X << 1 | 1] += tag[X] * (R - Mid);
    tag[X << 1] += tag[X];
    tag[X << 1 | 1] += tag[X];
    tag[X] = 0;
  }
  void update(int L, int R, int X, int A, int B, int V) {
    if(L > B || R < A) {
      return; 
    }  
    if (L >= A && R <= B) {
      sum[X] += (R - L + 1) * V;
      tag[X] += V;
      return;
    }
    pushdown(X, L, R);
    int Mid = L + R >> 1;
    update(L, Mid, X << 1, A, B, V);
    update(Mid + 1, R, X << 1 | 1, A, B, V);
    sum[X] = sum[X << 1] + sum[X << 1 | 1];
  }
  int query(int L, int R, int X, int A, int B) {
    if (L > B || R < A) {
      return 0;
    }
    if (L >= A && R <= B) {
      return sum[X];
    }
    pushdown(X, L, R);
    int Mid = L + R >> 1;
    return query(L, Mid, X << 1, A, B) + query(Mid + 1, R, X << 1 | 1, A, B);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> X(Q);
  vector<int> Y(Q);
  vector<int> W(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> X[i] >> Y[i] >> W[i];
    X[i] --;
    Y[i] --;
  }
  dsu dsu(N);
  hld hld(N);
  vector<bool> mark(Q);
  for (int i = 0; i < Q; ++i) {
    if (!dsu.same(X[i], Y[i])) {
      mark[i] = true;
      dsu.unite(X[i], Y[i]);
      hld.add(X[i], Y[i], W[i]);
    }
  }
  for (int i = 0; i < N; ++i) {
    if (!dsu.same(0, i)) {
      dsu.unite(0, i);
      hld.add(0, i, 0);
    }
  }
  hld.build_hld();
  sgt sgt(N);
  for (int i = 0; i < Q; ++i) {
    if (mark[i]) {
      cout << "YES" << '\n';
    } else {
      if (hld.ask(X[i], Y[i], [&] (int L, int R) -> int {
            if (L > R) {
              swap(L, R);
            }
            return sgt.query(0, N, 1, L, R);
          }, false) >= 1) { 
        cout << "NO" << '\n';
      } else {
        if ((hld.len(X[i], Y[i]) + W[i]) & 1) {
          hld.run(X[i], Y[i], [&] (int L, int R) -> void {
            if (L > R) {
              swap(L, R);
            }
            sgt.update(0, N, 1, L, R, 1); 
          }, false);
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      } 
    }
  }
}
