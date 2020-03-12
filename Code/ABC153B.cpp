#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, n;
	scanf("%d%d", &h, &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		h -= x;
	}
	puts(h > 0 ? "No" : "Yes");
	return 0;
}
