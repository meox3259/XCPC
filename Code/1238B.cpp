#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, r;
int x[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &r);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &x[i]);
		}
		sort(x + 1, x + n + 1);
		int m = 0;
		for(int i = 1; i <= n; ++i) {
			if(x[i] != x[m]) {
				x[++m] = x[i];
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++i) {
			if((x[i] + r - 1) / r > m - i) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
