#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
namespace flow {
    const int maxm = 1005, maxn = 1005, inf = 1e9;
    struct edge {
        int nxt, to, f;
    } e[maxm];
    int cnt = 1, source, sink;
    int d[maxn], h[maxn], iter[maxn];
    void link(int u, int v, int f) {
        e[++cnt].nxt = h[u];
        h[u] = cnt;
        e[cnt].to = v;
        e[cnt].f = f;
    }
    void insert(int u, int v, int f) {
        link(u, v, f);
        link(v, u, 0);
    }
    void init() {
        memset(h, 0, sizeof(h));
        cnt = 1;
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
}
int main() {
	int n, m;
	while(cin >> m >> n) {
		flow::init();
		for(int i = 1; i <= m; ++i) {
			int u, v, f;
			cin >> u >> v >> f;
			flow::insert(u, v, f);
		}
		flow::source = 1;
		flow::sink = n;
		cout << flow::dinic() << '\n';
	}
	return 0;
}
