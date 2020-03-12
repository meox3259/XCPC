#include <bits/stdc++.h>
using namespace std;
int tot;
namespace flow {
    const int maxm = 1e7 + 5, maxn = 5100, inf = 1e9;
	int fa1[maxn], fa2[maxn], id1[maxn], id2[maxn], id[maxn];
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
            for(int i = 0; i < tot + 5; ++i) iter[i] = h[i];
            ret += dfs(source, inf);
        }
        return ret;
    }
} using namespace flow;
int n, a, b;
int main() {
	init();
	scanf("%d", &n);
	scanf("%d", &a);
	source = ++tot;
	sink = ++tot;
	for(int i = 1; i <= n; ++i) id[i] = ++tot;
	for(int i = 2; i <= a; ++i) {
		int p; scanf("%d", &p);
		fa1[i] = p;
		id1[i] = ++tot;
		insert(source, tot, 1);
	}
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		while(x != 1) {
			insert(id1[x], id[i], 1);
			x = fa1[x];
		}
	}
	scanf("%d", &b);
	for(int i = 2; i <= b; ++i) {
		int p; scanf("%d", &p);
		fa2[i] = p;
		id2[i] = ++tot;
		insert(tot, sink, 1);
	}
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		while(x != 1) {
			insert(id[i], id2[x], 1);
			x = fa2[x];
		}
	}
	printf("%d\n", a + b - 2 - dinic());
	return 0;
}
