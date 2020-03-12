#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n, k;
ll h[maxn];
int main() {
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &h[i]);
	}
	sort(h + 1, h + n + 1);
	for(int i = 1; i <= n - k; ++i) {
		ans += h[i];
	}
	printf("%lld\n", ans);
	return 0;
}
