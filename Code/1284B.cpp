#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n, tot;
int mx[maxn], cnt[maxn], f[maxn];
long long ans;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int l, mn = 1e7; scanf("%d", &l);
		for(int j = 1; j <= l; ++j) {
			int x; scanf("%d", &x);
			mx[i] = max(mx[i], x);
			if(x > mn) {
				f[i] = 1;
			}
			mn = min(mn, x);
		}
		if(!f[i]) {
			++cnt[mn];
		} else {
			ans += n;
			++tot;
		}
	}
	for(int i = 1; i <= 1e6; ++i) {
		cnt[i] += cnt[i - 1];
	}
	for(int i = 1; i <= n; ++i) {
		if(!f[i]) {
			ans += tot;
			if(mx[i]) {
				ans += cnt[mx[i] - 1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
