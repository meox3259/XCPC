#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, q, cnt;
int a[maxn][3], ban[maxn];
int main() {
	scanf("%d%d", &n, &q);
	while(q--) {
		int r, c;
		scanf("%d%d", &r, &c);
		--r;
		a[c][r] ^= 1;
		if(c > 1) {
			int f = (a[c - 1][0] & a[c][1]) | (a[c - 1][1] & a[c][0]) | (a[c][0] & a[c][1]) | (a[c - 1][0] & a[c - 1][1]);
			if(f) {
				if(!ban[c - 1]) {
					ban[c - 1] = 1;
					++cnt;
				}
				ban[c - 1] = 1;
			} else {
				if(ban[c - 1]) {
					--cnt;
				}
				ban[c - 1] = 0;
			}
		}
		int f = (a[c + 1][0] & a[c][1]) | (a[c + 1][1] & a[c][0]) | (a[c][0] & a[c][1]) | (a[c + 1][0] & a[c + 1][1]);
		if(f) {
			if(!ban[c]) {
				ban[c] = 1;
				++cnt;
			}
			ban[c] = 1;
		} else {
			if(ban[c]) {
				--cnt;
			}
			ban[c] = 0;
		}
		puts(cnt ? "No" : "Yes");
	}
	return 0;
}
