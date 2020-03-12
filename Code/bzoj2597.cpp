#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5, inf = 0x3f3f3f3f;
struct edge {
    int nxt, to, f, c;
} e[maxn * 100];
int n, m, k, source, sink, cnt = 1;
int head[maxn], pree[maxn], Prev[maxn], vis[maxn], d[maxn];
inline void link(int u, int v, int f, int c) {
    e[++cnt].nxt = head[u];
    head[u] = cnt;
    e[cnt].f = f;
    e[cnt].to = v;
    e[cnt].c = c;
}
inline void insert(int u, int v, int f, int c) {
    link(u, v, f, c);
    link(v, u, 0, -c);
}
bool spfa() {
    memset(d, -1, sizeof(d));
    d[source] = 0;
	static int q[65540];
	static unsigned short l, r;
	q[++r] = source;
    while(l != r) {
		int u = q[l++];
		vis[u] = 0;
        for(int i = head[u]; i; i = e[i].nxt) {
			if(e[i].f && (d[e[i].to] > d[u] + e[i].c || d[e[i].to] == -1)) {
            	pree[e[i].to] = i;
           		Prev[e[i].to] = u;
            	d[e[i].to] = d[u] + e[i].c;
            	if(vis[e[i].to] == 0) {
					q[++r] = e[i].to;
                	vis[e[i].to] = 1;
            	}
        	}
		}
    }
    return ~d[sink]; 
}
inline int Edmonds_Karp() {
    int ans = 0;
    while(spfa()) {
        int now = sink, delta = inf;
        while(now != source) {
            delta = min(delta, e[pree[now]].f);
            now = Prev[now];
        }
        now = sink;
        while(now != source) {
            e[pree[now]].f -= delta;
            e[pree[now] ^ 1].f += delta; 
            now = Prev[now];
        }
        ans += delta * d[sink];
    } 
    return ans;
}
int a[105][105], id[105][105];
int main() {
	scanf("%d", &n);
	source = maxn - 2;
	sink = maxn - 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n - 1; ++j) {
			insert(source, i, 1, j);
		}
	}
	int tot = n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			insert(++tot, sink, 1, 0);
			if(a[i][j] == 0 || a[i][j] == 2) {
				insert(i, tot, 1, 0);
				id[j][i] = cnt - 1;
			}
			if(a[i][j] == 1 || a[i][j] == 2) {
				insert(j, tot, 1, 0);
				id[i][j] = cnt - 1;
			}
		}
	}
	int ans = n * (n - 1) * (n - 2) / 6;
	printf("%d\n", ans - Edmonds_Karp());
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j) {
				printf("0");
			} else {
				printf("%d", !id[i][j] || e[id[i][j]].f ? 0 : 1);
			}
			printf("%c", j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
