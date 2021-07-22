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

  vector<int> gen(int N) {
    vector<int> Ans(N, -1);
    set<int> S;
    for (int i = 0; i < N; ++i) {
      S.insert(i);
    }
    for (int X = 0; X < N; ++X) {
      for (int i : G[X]) {
        auto [Y, cap] = e[i];
        if (Y >= N && Y < N * 2 && cap == 0) {
          Ans[X] = Y - N; 
          S.erase(Y - N);
        }
      } 
    } 
    vector<int> wait;
    for (int i = 0; i < N; ++i) {
      if (Ans[i] == -1) {
        wait.push_back(i);
      }
    }
    vector<int> match(wait.size(), -1);
    for (int i = 0; i < wait.size(); ++i) {
      int X = wait[i];
      if (S.find(X) != S.end()) {
        match[i] = X;
        S.erase(X);
      }
    }
    for (int i = 0; i < wait.size(); ++i) {
      if (match[i] == -1) {
        match[i] = *S.begin();
        S.erase(S.begin());
      }
    }
    int P = wait.size();
    for (int i = 0; i < P; ++i) {
      Ans[wait[i]] = match[(i + 1) % P];
    }
    return Ans;
  } 
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      A[i] --;
    }
    MaxFlow<int> flow(N * 2 + 2);
    int source = N * 2;
    int sink = N * 2 + 1;
    for (int i = 0; i < N; ++i) {
      flow.AddEdge(source, i, 1);
      flow.AddEdge(i + N, sink, 1);
    }
    for (int i = 0; i < N; ++i) {
      flow.AddEdge(i, A[i] + N, 1);
    }
    int K = flow.dinic(source, sink);
    vector<int> Ans = flow.gen(N);
    if (K == N - 1) {
      int P = -1;
      vector<int> rev(N);
      for (int i = 0; i < N; ++i) {
        rev[Ans[i]] = i;
      }
      for (int i = 0; i < N; ++i) {
        if (Ans[i] == i) {
          P = i;
          break;
        }
      } 
      if (P != -1) {
        Ans[P] = A[P];
        Ans[rev[A[P]]] = P;
      }
    }
    cout << K << '\n';
    for (int i = 0; i < N; ++i) {
      cout << Ans[i] + 1 << " \n"[i == N - 1];
    }
  }
}
