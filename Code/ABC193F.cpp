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
                    q.emplace(y);
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

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int inf = numeric_limits<int> :: max() / 2;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    MaxFlow<int> flow(n * n * 2 + 5);
    int source = n * n * 2;
    int sink = n * n * 2 + 1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((~(i + j) & 1 && s[i][j] == 'B') || ((i + j) & 1 && s[i][j] == 'W')) {
                flow.AddEdge(i * n + j, sink, inf);
            }
            if ((~(i + j) & 1 && s[i][j] == 'W') || ((i + j) & 1 && s[i][j] == 'B')) {
                flow.AddEdge(source, i * n + j, inf);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                flow.AddEdge((i - 1) * n + j, i * n + j, 1);
                flow.AddEdge(i * n + j, (i - 1) * n + j, 1);
            } 
            if (j > 0) {
                flow.AddEdge(i * n + j - 1, i * n + j, 1);
                flow.AddEdge(i * n + j, i * n + j - 1, 1);
            }
        }
    }

    cout << 2 * n * (n - 1) - flow.dinic(source, sink) << '\n';

    return 0;
}
