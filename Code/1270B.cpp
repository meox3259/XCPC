#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
int main() {
	int T; scanf("%d", &T);
	/*
	 x - y >= len
	 x - i - (y - j) >= 0
	 i - j + 1 = len
	 */
	while(T--) {
		scanf("%d", &n);
		bool f = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for(int i = 2; i <= n; ++i) {
			if(abs(a[i] - a[i - 1]) > 1) {
				f = 1;
				puts("YES");
				printf("%d %d\n", i - 1, i);
				break;
			}
		}
		if(!f) {
			puts("NO");
		}
	}
	return 0;
}
