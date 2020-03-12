#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
pair<int, int> f[maxn], g[maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			int l, a, b;
			scanf("%d%d%d", &l, &a, &b);
			f[i] = make_pair(a, l);
			g[i] = make_pair(b, l);
		}
		sort(f + 1, f + n + 1);
		sort(g + 1, g + n + 1);
		ll tot = 0;
		bool flag = 1;
		for(int i = 1, j = 1; i <= n; ++i) {
			while(f[i].second) {
				while(!g[j].second && j < n) {
					++j;
				}
				ll tmp = min(f[i].second, g[j].second);
				f[i].second -= tmp;
				g[j].second -= tmp;
				tot += 1LL * tmp * (g[j].first - f[i].first);
				if(tot < 0) {
					flag = 0;
				}
			}
		}	
		if(tot != 0) {
			flag = 0;
		}
		puts(flag ? "TAK" : "NIE");
	}
	return 0;
}
