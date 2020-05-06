#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

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

class FoxAndGo3 {
	public:
	int maxEmptyCells(vector <string> b) {
		int n = b.size();
		int tot = 0;
		int ans = 0;
		vector<vector<int> > id(n, vector<int> (n, 0));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				id[i][j] = ++tot;
			}
		}
		int source = 0;
		int sink = ++tot;
		flow<int> flow(tot, tot * 8, source, sink);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(b[i][j] == '.') {
					flow.add_edge(source, id[i][j], 1);
					++ans;
				} else if(b[i][j] == 'o') {
					flow.add_edge(id[i][j], sink, 1);
					for(int k = 0; k < 4; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if(0 <= x && x < n && 0 <= y && y < n && b[x][y] == '.') {
							flow.add_edge(id[x][y], id[i][j], inf);
						}
					}
					++ans;
				}
			}
		}
		return ans - flow.dinic();
	}
};

