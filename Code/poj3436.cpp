#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1000000000;
const int maxn = 6005, maxm = 100005;
class flow {
    public:
    	struct edge {
        	int nxt, to, f, cap;
    	} e[maxm];
   		int tot, source, sink;
    	int d[maxn], h[maxn], iter[maxn];
    	void link(int u, int v, int f) {
        	e[++tot].nxt = h[u];
        	h[u] = tot;
        	e[tot].to = v;
        	e[tot].f = f;
			e[tot].cap = f;
    	}
    	void add_edge(int u, int v, int f) {
        	link(u, v, f);
        	link(v, u, 0);
    	}
    	void init() {
        	memset(h, 0, sizeof(h));
        	tot = 1;
        	source = sink = 0;
    	}
    	bool bfs() {
        	queue<int> q;
        	memset(d, -1, sizeof(d));
        	d[source] = 0;
        	q.push(source);
        	while(!q.empty()) {
            	int u = q.front(); q.pop();
            	for(int i = h[u]; i; i = e[i].nxt) if(d[e[i].to] == -1 && e[i].f) {
                	d[e[i].to] = d[u] + 1;
                	q.push(e[i].to);
            	}
        	}
        	return ~d[sink];
    	}
    	int dfs(int u, int f) {
        	if(u == sink) return f;
        	int ret = 0;
        	for(int &i = iter[u]; i && f; i = e[i].nxt) if(d[e[i].to] == d[u] + 1 && e[i].f) {
            	int x = dfs(e[i].to, min(f, e[i].f));
            	ret += x;
            	f -= x;
            	e[i].f -= x;
            	e[i ^ 1].f += x;
        	}
        	return ret;
    	}
    	int dinic() {
        	int ret = 0;
        	while(bfs()) {
            	for(int i = 0; i < maxn; ++i) iter[i] = h[i];
            	ret += dfs(source, inf);
        	}
        	return ret;
    	}
		void print(int n) {
			int flow = dinic();
			vector<vector<int> > ans;
			for(int i = n + 1; i < sink; ++i) {
				for(int j = h[i]; j; j = e[j].nxt) {
					if(e[j].to <= n && e[j ^ 1].f && e[j].cap == inf && e[j].to != i - n) {
						vector<int> tmp;
						tmp.resize(3);
						tmp[2] = e[j ^ 1].f;
						tmp[0] = i - n;
						tmp[1] = e[j].to;
						ans.push_back(tmp);
					}
				}
			}
			cout << flow << ' ' << ans.size() << '\n';
			for(int i = 0; i < ans.size(); ++i) {
				cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
			}
		}
};
int main() {
	int n, p;
	cin >> p >> n; 
	flow flow;
	flow.init();
	vector<int> val;
	vector<vector<int> > in;
	vector<vector<int> > out;
	val.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> val[i];
		in[i].resize(p);
		for(int j = 0; j < p; ++j) {
			cin >> in[i][j];
		}
		out[i].resize(p);
		for(int j = 0; j < p; ++j) {
			cin >> out[i][j];
		}
	}
	flow.source = 0;
	flow.sink = n * 2 + 1;
	for(int i = 1; i <= n; ++i) {
		bool f = 1;
		for(int j = 0; j < p; ++j) {
			if(in[i][j] == 1) {
				f = 0;
				break;
			}
		}
		if(f) {
			flow.add_edge(flow.source, i, inf);
		}
	}
	for(int i = 1; i <= n; ++i) {
		flow.add_edge(i, i + n, val[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i != j) {
				bool f = 1;
				for(int k = 0; k < p; ++k) {
					if(out[i][k] != in[j][k] && in[j][k] != 2) {
						f = 0;
						break;
					}
				}
				if(f) {
					flow.add_edge(i + n, j, inf);
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		bool f = 1;
		for(int j = 0; j < p; ++j) {
			if(out[i][j] != 1) {
				f = 0;
				break;
			}
		}
		if(f) {
			flow.add_edge(i + n, flow.sink, inf);
		}
	}
	flow.print(n);
	return 0;
}
