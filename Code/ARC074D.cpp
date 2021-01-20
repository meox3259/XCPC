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

	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	for (int i = 0; i < h; ++i) {
		cin >> s[i];
	}

	auto id = [&] (int x, int y) {
		return x * w + y;
	};

	int sx = -1;
	int sy = -1;
	int source = -1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
				source = i;
			}
		}
	}

	int tx = -1;
	int ty = -1;
	int sink = -1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == 'T') {
				tx = i;
				ty = j;
				sink = j;
			}
		}
	}

	if (sx == tx || sy == ty) {
		cout << -1 << '\n';
		exit(0);
	}

	MaxFlow<int> flow(h * w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == 'o') {
				flow.AddEdge(i, j + h, 1);
				flow.AddEdge(j + h, i, 1);
			}
		}
	}

	int ans = 0;
	ans += flow.dinic(sx, tx);
	ans += flow.dinic(sx, ty + h);
	ans += flow.dinic(sy + h, tx);
	ans += flow.dinic(sy + h, ty + h);
	cout << ans << '\n';

	return 0;
}
