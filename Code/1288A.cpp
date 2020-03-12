#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while(T--) {
		long long n, d; cin >> n >> d;
		long long mn = 1e18;
		for(long long i = 0; i * i <= 2 * d; ++i) {
			mn = min(mn, i + ((d + i) / (i + 1)));
		}
		puts(mn <= n ? "YES" : "NO");
	}
	return 0;
}
