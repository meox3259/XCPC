#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if(a > b) {
			swap(a, b);
		}
		ll d = b - a;
		if(d == 0) {
			puts("0");
			continue;
		}
		ll p = 0;
		for(ll i = 1; ; ++i) {
			if((i + 1) * i / 2 >= d) {
				p = i;
				break;
			}
		}
		ll s = (p + 1) * p / 2;
		if((d & 1) == (s & 1)) {
			printf("%lld\n", p);
		} else {
			while((d & 1) != (((p + 1) * p / 2) & 1)) ++p;
			printf("%lld\n", p);
		}
	}
	return 0;
}
