#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> b;
		for (int i = 1; i < n; ++i) {
			b.emplace_back(a[i] - a[i - 1]);
		}

		long long sum = 0;
		for (int i : b) {
			sum += abs(i);
		}

		long long ans = sum - abs(b[0]);
		for (int i = 1; i < b.size(); ++i) {
			ans = min(ans, sum - abs(b[i]) - abs(b[i - 1]) + abs(b[i] + b[i - 1]));
		}
		ans = min(ans, sum - abs(b.back()));

		cout << ans << '\n';
	}

	return 0;
}
