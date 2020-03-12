#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const ll inf = 1e18;
int n;
ll k;
ll a[maxn], sum[maxn];
bool c(ll d) {
	ll mn = inf;
	for(int i = 1, j = 0; i <= n; ++i) {
		while(j + 1 <= n && a[j + 1] - a[i] <= d) {
			++j;
		}
		mn = min(mn, a[i] * i - sum[i] + sum[n] - sum[j] - (a[i] + d) * (n - j));
	}
	for(int i = 1, j = 1; i <= n; ++i) {
		while(a[i] - a[j] > d) {
			++j;
		}
		mn = min(mn, sum[n] - sum[i] - a[i] * (n - i) + (a[i] - d) * (j - 1) - sum[j - 1]);
	}
	return mn <= k;
}
int main() {
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		sum[i] = a[i] + sum[i - 1];
	}
	int l = -1, r = a[n] - a[1] + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(c(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%d\n", r);
	return 0;
}
