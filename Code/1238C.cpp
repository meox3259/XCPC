#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, h;
int p[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &h, &n);
		p[n + 1] = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);	
		}
		int len = 0, ans = 0;
		for(int i = 1; i <= n; ++i) {
			++len;
			if(p[i + 1] != p[i] - 1) {
				if(len % 2 == 0) {
					ans += (p[i] != 1);
					len = 1;
				} else {
					len = 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
