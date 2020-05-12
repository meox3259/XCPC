#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		int div = n;

		for(int i = 2; i * i <= n; ++i) {
			if(n % i == 0) {
				div = i;
				break;
			}
		}

		long long ans = n;
		ans = ans + div + (k - 1) * 2;

		cout << ans << '\n';
	}

	return 0;
}
