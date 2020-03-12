#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int P = 1e9 + 7;
int n, m;
long long a[12][maxn], b[12][maxn];
int main() {
	cin >> n >> m;	
	for(int i = 1; i <= n; ++i) {
		a[1][i] = 1;
		b[1][i] = 1;
	}
	for(int i = 2; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= j; ++k) {
				a[i][j] = (a[i][j] + a[i - 1][k]) % P;
			}
			for(int k = j; k <= n; ++k) {
				b[i][j] = (b[i][j] + b[i - 1][k]) % P;
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			ans = (ans + b[m][i] * a[m][j] % P) % P;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
