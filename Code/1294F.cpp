#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, ans;
int d[maxn], c[maxn];
vector<int> G[maxn];
int bfs(int s) {
	memset(d, -1, sizeof(d));
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	int ret = 1;
	for(int i = 1; i <= n; ++i) {
		if(d[i] > d[ret]) {
			ret = i;
		}
	}
	return ret;
}
void dfs(int u) {
	for(auto v : G[u]) {
		if(!c[v]) {
			c[v] = 1;
			d[v] = d[u] + 1;
			dfs(v);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int s = bfs(1), t = bfs(s), ans = d[t];
	int now = t;
	vector<int> vec;
	vec.push_back(t);
	c[t] = 1;
	while(now != s) {
		for(auto v : G[now]) {
			if(d[v] + 1 == d[now]) {
				now = v;
				vec.push_back(v);
				c[v] = 1;
				break;
			}
		}
	}
	memset(d, 0, sizeof(d));
	for(auto x : vec) {
		dfs(x);
	}
	int last = 0;
	for(int i = 1; i <= n; ++i) {
		if(i != s && i != t) {
			last = i;
			break;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(d[i] > d[last]) {
			last = i;
		}
	}
	printf("%d\n", ans + d[last]);
	printf("%d %d %d\n", s, t, last);
	return 0;
}
