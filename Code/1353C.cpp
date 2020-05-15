#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		long long n;
		cin >> n;
		long long m = n / 2 + 1;

		long long ans = 0;
		ans = ans + (n * n - 1) * (n + 1) / 2;
		ans = ans - m * (4 * m * m - 1) / 3;
		ans = ans + m;

		cout << ans << '\n';
	}

	return 0;
}
