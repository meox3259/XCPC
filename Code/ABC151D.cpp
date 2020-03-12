#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m;
int d[maxn][maxn];
char s[maxn][maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	int ans = 0;
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '.') {
				memset(d, -1, sizeof(d));
				d[i][j] = 0;
				q.push(i);
				q.push(j);
				while(!q.empty()) {
					int x = q.front(); q.pop();
					int y = q.front(); q.pop();
					for(int k = 0; k < 4; ++k) {
						int xx = x + dx[k], yy = y + dy[k];
						if(s[xx][yy] == '.' && d[xx][yy] == -1) {
							q.push(xx);
							q.push(yy);
							d[xx][yy] = d[x][y] + 1;
						}
					}
				}
				for(int x = 1; x <= n; ++x) {
					for(int y = 1; y <= m; ++y) {
						ans = max(ans, d[x][y]);
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
