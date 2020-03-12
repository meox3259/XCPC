#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n;
char s[maxn];
int main() {
	scanf("%d%s", &n, s + 1);
	long long ans = 1LL * n * (n + 1) / 2 - n;
	for(int i = 1, j; i <= n; i = j) {
		j = i;
		while(j + 1 <= n && s[j + 1] != s[i]) {
				++j;
		}
		ans -= j - i;
		if(j == i) {
			++j;
		}
	}
	reverse(s + 1, s + n + 1);
	for(int i = 1, j; i <= n; i = j) {
		j = i;
		while(j + 1 <= n && s[j + 1] != s[i]) {
			++j;
		}
		ans -= j - i;
		if(j == i) {
			++j;
		}
	}
	for(int i = 1; i < n; ++i) {
		ans += (s[i] != s[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}
