#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
vector<int> G[maxn];
int n;
int vis[maxn];
char s[maxn];
void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		dfs(v);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int j = 1; j <= len; ++j) {
			G[i].push_back(s[j] - 'a' + 1 + n);
			G[s[j] - 'a' + 1 + n].push_back(i);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			++ans;
			dfs(i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
