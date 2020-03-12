#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a = i % 10, b = i;
		while(b > 9) {
			b /= 10;	
		}
		if(!a) {
			continue;
		}
		ans += (a == b);
		int bin = 1;
		for(int j = 1; j <= 5; ++j) {
			for(int k = 0; k < bin; ++k) {
				if(k * 10 + a * bin * 10 + b <= n) {
					++ans;
				} else {
					break;
				}
			}
			bin *= 10;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
