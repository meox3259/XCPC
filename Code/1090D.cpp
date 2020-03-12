#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
set<pair<int, int> > s;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		s.insert(make_pair(x, y));
	}
	if(m == 1LL * n * (n - 1) / 2) return puts("NO");
	for(int i = 1; i < n; ++i) {
		bool f = 0;
		for(int j = i + 1; j <= n; ++j) 
			if(s.find(make_pair(i, j)) == s.end()) {
				x = i;
				y = j;
				f = 1;
				break;
			}
		if(f) break;
	}
	int c = 2;
	puts("YES");
	for(int i = 1; i <= n; ++i) {
		if(i == x) printf("1 ");
		else if(i == y) printf("2 ");
		else printf("%d ", ++c);
	}
	puts("");
	c = 2;
	for(int i = 1; i <= n; ++i) {
		if(i == x || i == y) printf("1 ");
		else printf("%d ", ++c);
	}
	return 0;
}
