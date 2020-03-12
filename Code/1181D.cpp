#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
int n, m, q;
int c[maxn];
ll a[maxn];
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		a[i] = 1LL * (c[x]++) * m + x;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) a[i] -= i;
	while(q--) {
		ll k; scanf("%lld", &k);
		k += lower_bound(a + 1, a + n + 1, k - n) - a - n - 1;
		printf("%lld\n", (k - 1) % m + 1);
	}
	return 0;
}
