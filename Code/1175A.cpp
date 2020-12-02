#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		long long n, k;
		cin >> n >> k;

		long long ans = 0;
		while (n != 0) {
			ans += n % k;
			if (n >= k) {
				ans += 1;
			}
			n /= k;
		}

		cout << ans << '\n';
	}

	return 0;
}
