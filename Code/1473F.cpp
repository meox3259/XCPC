#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max() / 2;

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

bitset<3000> c[3000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	int ans = 0;
	for (int i : b) {
		if (i >= 0) {
			ans += i;
		}
	}

	int source = n;
	int sink = n + 1;
	MaxFlow<int> flow(n + 2);

	for (int i = 0; i < n; ++i) {
		if (b[i] >= 0) {
			flow.AddEdge(source, i, b[i]);
		} else {
			flow.AddEdge(i, sink, -b[i]);
		}
		for (int j = i - 1; j >= 0; --j) {
			if (a[i] % a[j] == 0) {
				if (!c[i][j]) {
					c[i][j] = 1;
					flow.AddEdge(i, j, inf);
				}	
				c[i] |= c[j];
			}
		}
	}
	
	cout << ans - flow.dinic(source, sink) << '\n';

	return 0;
}
