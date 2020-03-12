#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n, m;
int vis[maxn][maxn];
char s[maxn][maxn];
void dfs(int x, int y) {
	if(vis[x][y] || x < 1 || y < 1 || x > n || y > m) {
		return;
	}
	vis[x][y] = 1;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
	dfs(x - 1, y - 1);
	dfs(x - 1, y + 1);
	dfs(x + 1, y - 1);
	dfs(x + 1, y + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '.') {
				vis[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(!vis[i][j]) {
				dfs(i, j);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
