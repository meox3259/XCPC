#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
	scanf("%d", &n);
	while(n) {
		n >>= 1;
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}
