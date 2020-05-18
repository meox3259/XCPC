#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

template <class T>
class flow {
	class edge {
		public:
		int nxt, to;
		T f;
		edge() = default;
		edge(int _nxt, int _to, T _f) : nxt(_nxt), to(_to), f(_f) {}
	};

	vector<int> d;
	vector<int> h;
	vector<int> iter;
	vector<edge> e;
	int cnt, source, sink;

	public:
	flow(int N, int M, int _source, int _sink) : h(N + 1), e(M * 2 + 5), source(_source), sink(_sink) {
		cnt = 1;
	}

    void link(int u, int v, T f) {
        e[++cnt].nxt = h[u];
        h[u] = cnt;
        e[cnt].to = v;
        e[cnt].f = f;
    }

    void add_edge(int u, int v, T f) {
        link(u, v, f);
        link(v, u, 0);
    }

    bool bfs() {
		d.assign(h.size(), -1);
		d[source] = 0;

        queue<int> q;
        q.emplace(source);

        while(!q.empty()) {
            int u = q.front(); 
			q.pop(); 
			for(int i = h[u]; i; i = e[i].nxt) {
				if(d[e[i].to] == -1 && e[i].f) {
                	d[e[i].to] = d[u] + 1;
                	q.emplace(e[i].to);
            	}
			}
        }
        return ~d[sink];
    }

    T dfs(int u, T f) {
        if(u == sink) {
			return f;
		}

        T ret = 0;   
		for(int &i = iter[u]; i && f; i = e[i].nxt) {
			if(d[e[i].to] == d[u] + 1 && e[i].f) {
            	T x = dfs(e[i].to, min(f, e[i].f));
           		ret += x;
            	f -= x;
            	e[i].f -= x;
            	e[i ^ 1].f += x;
        	}
		}

        return ret;
    }

    T dinic() {
        T ret = 0;  
		while(bfs()) {
			iter = h;
            ret += dfs(source, inf);
        }
        return ret;
    }
};

const char c[] = { 'R', 'G', 'B' };

class GearsDiv1 {
	public:
	int getmin(string color, vector <string> graph) {
		int n = color.size();
		int ans = n;
		for(int a = 0; a < 3; ++a) {
			for(int b = a + 1; b < 3; ++b) {
				int source = n;
				int sink = n + 1;
				flow<int> flow(n + 2, n * n * 2, source, sink);
				for(int i = 0; i < n; ++i) {
					if(color[i] == c[a]) {
						flow.add_edge(source, i, 1);
					} else if(color[i] == c[b]) {
						flow.add_edge(i, sink, 1);
					}
				}
				for(int i = 0; i < n; ++i) {
					if(color[i] == c[a]) {
						for(int j = 0; j < n; ++j) {
							if(color[j] == c[b] && graph[i][j] == 'Y') {
								flow.add_edge(i, j, 1);
							} 
						}
					}
				}
				ans = min(ans, flow.dinic());
			}
		}
		return ans;
	}
};
