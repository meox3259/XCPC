#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn], cnt[maxn];
int main() {
	scanf("%d", &n);
	long long ans = 0;
	int pre = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		ans += a[i] / 2;
		if(a[i] & 1) {
			if(cnt[(i & 1) ^ 1]) {
				--cnt[(i & 1) ^ 1];
				++ans;
			} else {
				++cnt[i & 1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
