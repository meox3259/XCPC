#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m ;
int a[maxn], tot[maxn];
long long ans;
map<pair<int, int>, int> mp;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ans += a[i];
	}
	scanf("%d", &m);
	while(m--) {
		int s, t, u; scanf("%d%d%d", &s, &t, &u);
		int p = mp[make_pair(s, t)];
		if(p != 0) {
			--tot[p];
			if(tot[p] < a[p]) {
				++ans;
			}
		}
		if(u != 0) {
			++tot[u];
			if(tot[u] <= a[u]) {
				--ans;
			}
		}
		mp[make_pair(s, t)] = u;
		printf("%lld\n", ans);
	}
	return 0;
}
