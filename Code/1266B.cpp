#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		long long x;
		scanf("%lld", &x);
		if(x < 15) {
			puts("NO");
			continue;
		}
		x %= 14LL;
		if(x >= 1 && x < 7) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
