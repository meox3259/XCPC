#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
struct node {
	int x, y;
	node() = default;
	node(int _x, int _y) : x(_x), y(_y) {}
	bool friend operator < (const node &a, const node &b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
} a[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a + 1, a + n + 1);
		bool f = 1;
		for(int i = 1; i <= n; ++i) {
			if(a[i].y < a[i - 1].y) {
				f = 0;
				break;
			}
		}
		if(!f) {
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= a[i].x - a[i - 1].x; ++j) {
				printf("R");
			}
			for(int j = 1; j <= a[i].y - a[i - 1].y; ++j) {
				printf("U");
			}
		}
		puts("");
	}
	return 0;
}
