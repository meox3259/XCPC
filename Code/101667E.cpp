#include <bits/stdc++.h>
using namespace std;
template <class flow_t>
class MaxFlow {
 private:
  class Edge {
    private:
    public:
      int to;
      flow_t cap;
      Edge() {}
      Edge(int to, flow_t cap) : to(to), cap(cap) {}
  };
  vector<Edge> e;
  vector<vector<int> > G;
  vector<int> iter, d;
  int n;
 public:
  MaxFlow() {}
  MaxFlow(int n) : n(n), G(n) {}
  void AddEdge(int x, int y, flow_t c) {
    G[x].push_back(e.size());
    e.emplace_back(y, c);
    G[y].push_back(e.size());
    e.emplace_back(x, 0);
  }
  bool bfs(int source, int sink) {
    d.assign(n, -1);
    queue<int> q;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i : G[x]) {
        auto [y, cap] = e[i];
        if (cap > 0 && d[y] == -1) {
          d[y] = d[x] + 1;
          if (y == sink) {
            return true;
          }
          q.push(y);
        }
      }
    }
    return false;
  }
  flow_t dfs(int x, int sink, flow_t f) {
    if (x == sink) {
      return f;
    }
    flow_t ret = 0;
    for (int &i = iter[x]; i < int(G[x].size()); ++i) {
      int j = G[x][i];
      auto [y, cap] = e[j];
      if (cap > 0 && d[y] == d[x] + 1) {
        flow_t delta = dfs(y, sink, min(f, cap));
        e[j].cap -= delta;
        e[j ^ 1].cap += delta;
        f -= delta;
        ret += delta;
        if (f == 0) {
          return ret;
        }
      }
    }
    return ret;
  }
  flow_t dinic(int source, int sink) {
    flow_t ret = 0;
    while (bfs(source, sink)) {
      iter.assign(n, 0);
      ret += dfs(source, sink, numeric_limits<flow_t>::max() / 2);
    }
    return ret;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    x --;
    y --;
    e.emplace_back(x, y, w); 
  }
  sort(e.begin(), e.end(), [&] (tuple<int, int, int> x, tuple<int, int, int> y) {
    return get<2>(x) < get<2>(y);
  });
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    MaxFlow<int> flow(n);    
    for (auto [x, y, w] : e) {
      if (w >= get<2>(e[i])) {
        break;
      }
      flow.AddEdge(x, y, 1);
      flow.AddEdge(y, x, 1);
    }
    ans += flow.dinic(get<0>(e[i]), get<1>(e[i]));
  }
  cout << ans << '\n';
}
