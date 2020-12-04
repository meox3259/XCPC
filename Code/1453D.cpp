#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		long long k;
		cin >> k;

		if (k % 2 == 1) {
			cout << -1 << '\n';
		} else {
			vector<int> d;
			int n = 0;

			vector<long long> sum(64);
			for (int i = 1; i < 63; ++i) {
				for (int j = 1; j <= i; ++j) {
					sum[i] += 1LL << j;
				}
			}

			for (int i = 62; i >= 1; --i) {
				while (k >= sum[i]) {
					k -= sum[i];
					d.emplace_back(i);
					n += i;
				}
			}

			cout << n << '\n';
			for (int i : d) {
				cout << 1 << ' ';
				for (int j = 0; j < i - 1; ++j) {
					cout << 0 << ' ';
				}
			}
			cout << '\n';
		}
	}

	return 0;
}
