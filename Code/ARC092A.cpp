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

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<int> c(n);
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i] >> d[i];
	}

	MaxFlow<int> flow(n + n + 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i] < c[j] && b[i] < d[j]) {
				flow.AddEdge(i, j + n, 1);
			}
		}
	}

	int source = n + n;
	for (int i = 0; i < n; ++i) {
		flow.AddEdge(source, i, 1);
	}

	int sink = n + n + 1;
	for (int i = 0; i < n; ++i) {
		flow.AddEdge(i + n, sink, 1);
	}

	cout << flow.dinic(source, sink) << '\n';
	
	return 0;
}
