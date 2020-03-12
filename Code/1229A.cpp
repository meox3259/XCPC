#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 7005;
int n;
ll a[maxn], b[maxn];
bool f[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		int c = 0;
		for(int j = 1; j <= n; ++j) {
			if(a[i] == a[j]) {
				++c;
			}
		}
		if(c > 1) {
			f[i] = 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if((a[i] & a[j]) == a[i]) {
				f[i] |= f[j];
			}
		}
		if(f[i]) {
			ans += b[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
