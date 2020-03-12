#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1000000000;
const int maxn = 1005, maxm = 100005;
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
};
int main() {
	int n, m;
	while(cin >> n >> m) {
		flow flow;
		flow.init();
		flow.source = 0;
		flow.sink = n + m + 1;
		vector<int> stall;
		for(int i = 1; i <= n; ++i) {
			int s;
			cin >> s;
			flow.add_edge(flow.source, i, 1);
			while(s--) {
				int x;
				cin >> x;
				stall.push_back(x);
				flow.add_edge(i, x + n, 1);
			}
		}
		sort(stall.begin(), stall.end());
		stall.erase(unique(stall.begin(), stall.end()), stall.end());
		for(int i = 0; i < stall.size(); ++i) {
			int t = stall[i];
			flow.add_edge(t + n, flow.sink, 1);
		}
		cout << flow.dinic() << '\n';
	}
	return 0;
}
