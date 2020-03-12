#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, k;
int a[maxn], b[maxn];
char s[maxn];
int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	for(int i = 1; i <= n; ++i) {
		a[i] = s[i] - '0';
	}
	int m = n;
	for(int i = 1; i < k; ++i) {
		for(int j = i; j <= n; j += k) {
			b[j] = a[i];
		}
	}
	for(int i = k; i <= n; i += k) {
		b[i] = a[k];
	}
	bool f = 1;
	for(int i = 1; i <= n; ++i) {
		if(b[i] > a[i]) {
			break;
		}
		if(b[i] < a[i]) {
			f = 0;
			break;
		}
	}
	if(f) {
		printf("%d\n", n);
		for(int i = 1; i <= n; ++i) {
			printf("%d", b[i]);
		}
		return 0;
	}
	for(int i = k; i; --i) {
		if(b[i] != 9) {
			b[i] = a[i] + 1;
			for(int j = i; j <= n; j += k) {
				b[j] = a[i] + 1;
			}
			printf("%d\n", n);
			for(int j = i + 1; j <= k; ++j) {
				for(int l = j; l <= n; l += k) {
					b[l] = 0;
				}
			}
			for(int j = 1; j <= n; ++j) {
				printf("%d", b[j]);
			}
			return 0;
		}
	}
	printf("%d\n", n + 1);
	memset(b, 0, sizeof(0));
	b[1] = 1;
	for(int i = 1; i <= n + 1; i += k) {
		b[i] = 1;
	}
	for(int i = 1; i <= n + 1; ++i) {
		printf("%d", b[i]);
	}
	return 0;
}
