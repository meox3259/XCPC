#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int a, b, c, r; scanf("%d%d%d%d", &a, &b, &c, &r);
		int ans = 0;
		if(a > b) {
			swap(a, b);
		}
		ans += max(0, c - r - a) + max(0, b - (r + c));
		printf("%d\n", min(ans, b - a));
	}
	return 0;
}
