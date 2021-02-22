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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    MaxFlow<int> flow(n * m * 2 + 2);

    int ans = 0;
    int edge = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                ans ++;
                vector<int> row;
                vector<int> col;
                if (j > 0 && s[i][j - 1] == '#') {
                    row.emplace_back(i * m + j - 1);
                    edge ++;
                } 
                if (j < m - 1 && s[i][j + 1] == '#') {
                    row.emplace_back(i * m + j);
                    edge ++;
                }
                if (i > 0 && s[i - 1][j] == '#') {
                    col.emplace_back(i * m + j - m);
                    edge ++;
                }
                if (i < n - 1 && s[i + 1][j] == '#') {
                    col.emplace_back(i * m + j);
                    edge ++;
                }
                for (int x : row) {
                    for (int y : col) {
                        flow.AddEdge(x, y + n * m, 1);
                    }
                }
            } 
        }
    }

    edge /= 2;

    int source = n * m * 2;
    int sink = n * m * 2 + 1;
    for (int i = 0; i < n * m; ++i) {
        flow.AddEdge(source, i, 1);
        flow.AddEdge(i + n * m, sink, 1);
    }

    cout << ans - edge + flow.dinic(source, sink) << '\n';

    return 0;
}
