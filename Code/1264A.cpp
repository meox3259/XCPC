#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n;
int p[maxn];
int main() {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> p[i];
		p[n + 1] = -1;
		p[0] = -1;
		int g = 0, s = 0, b = 0;
		for(int i = 1; i <= n; ++i) {
			if(p[i] != p[i + 1]) {
				g = i;
				break;
			}
		}
		for(int i = g + 1; i <= n; ++i) if(i - g > g) {
			if(p[i] != p[i + 1]) {
				s = i;
				break;
			}
		}
		for(int i = s + 1; i <= n; ++i) {
			if(p[i] != p[i + 1]) {
				b = i;
				break;
			}
		}
		if(g  > n / 2 || s > n / 2 || b > n / 2) {
			puts("0 0 0");
			continue;
		}
		b = n / 2 - s;
		for(int i = n / 2 + 1; i; --i) {
			if(p[i] != p[i - 1]) {
				break;
			}
			--b;
		}
		s -= g;
		if(g >= s || g >= b) {
			puts("0 0 0");
			continue;
		}
		printf("%d %d %d\n", g, s, b);
	}
	return 0;
}
