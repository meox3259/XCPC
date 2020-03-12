#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, k;
int t[maxn];
char s[maxn];
int inc(int x) {
	return (x + 1) % n;
}
int dec(int x) {
	return (x - 1 + n) % n;
}
int main() {
	memset(t, 0x3f3f, sizeof(t));
	scanf("%d%d%s", &n, &k, s);
	for(int i = 0; i < n; ++i) {
		if(s[i] == s[inc(i)] || s[i] == s[dec(i)]) {
			t[i] = 0;
		}
	}
	for(int i = 0; i < 2 * n; ++i) {
		t[i % n] = min(t[i % n], t[dec(i)] + 1);
	}
	for(int i = 2 * n - 1; ~i; --i) {
		t[i % n] = min(t[i % n], t[inc(i)] + 1);
	}
	for(int i = 0; i < n; ++i) {
		if(min(t[i], k) & 1) {
			printf("%c", 'W' + 'B' - s[i]);
		} else {
			printf("%c", s[i]);
		}
	}
	return 0;
}
