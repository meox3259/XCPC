#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<pair<int, int> > ans;
		while (n > 2) {
			int m = ceil(sqrt(n));
			for (int i = m + 1; i < n; ++i) {
				ans.emplace_back(i, i + 1);
			}
			ans.emplace_back(n, m);
			ans.emplace_back(n, m);
			n = m;
		}

		cout << ans.size() << '\n';

		for (auto [x, y] : ans) {
			cout << x << ' ' << y << '\n';
		}
	}

	return 0;
}
