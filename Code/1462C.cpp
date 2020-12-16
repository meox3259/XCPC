#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	while (T--) {
		int x;
		cin >> x;

		vector<int> num(10);
		iota(num.begin(), num.end(), 0);
		long long ans = inf;
		for (int S = 0; S < 1 << 10; ++S) {
			int sum = 0;
			long long y = 0;
			for (int i = 0; i < 10; ++i) {
				if (S >> i & 1) {
					sum += num[i];
					y = y * 10 + num[i];
				}
			}
			if (sum == x) {
				ans = min(ans, y);
			}
		}

		if (ans == inf) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}

	return 0;
}
