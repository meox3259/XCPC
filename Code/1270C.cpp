#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int n;
ll a[maxn], st[maxn];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		ll s = 0, sum = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			s ^= a[i];
			sum += a[i];
		}
		int top = 0;
		st[++top] = s;
		st[++top] = sum + s;
		printf("%d\n", top);
		for(int i = 1; i <= top; ++i) {
			printf("%lld ", st[i]);
		}
		puts("");
	}
	return 0;
}
