#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		int ans = n;

		for(int i = 1; i * i <= n; ++i) {
			if(n % i == 0) {
				int x = i;
				int y = n / i;
				if(x <= k) {
					ans = min(ans, n / x);
				}
				if(y <= k) {
					ans = min(ans, n / y);	
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
