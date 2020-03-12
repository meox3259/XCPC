#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 1e7 + 6, P = 1e9 + 7;
int n;
char s[maxm];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int x;
		long long ans = 0;
		scanf("%d%s", &x, s + 1);
		n = strlen(s + 1);
		long long r = n;
		bool f = 0;
		for(int i = 1; i <= x; ++i) {
			int t = s[i] - '0', cur_r = r;
			if(r > x) {
				f = 1;
			}
			if(!f) {
				for(int j = 0; j < t - 1; ++j) {
					for(int k = i + 1; k <= cur_r; ++k) {
						s[++r] = s[k];
					}
				}
			} else {
				r = (r + 1LL * (t - 1) * (r - i + P) % P) % P;
			}
		}
		printf("%lld\n", r);
	}
	return 0;
}
