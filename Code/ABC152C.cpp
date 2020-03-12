#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int mn = n + 1, ans = 0;
	for(int i = 1; i <= n; ++i) {
		int x; 
		scanf("%d", &x);
		mn = min(mn, x);
		ans += (mn >= x);
	}
	printf("%d\n", ans);
	return 0;
}
