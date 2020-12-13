#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	a.emplace_back(0);
	a.emplace_back(n + 1);
	sort(a.begin(), a.end());
	long long ans = 0;
	int k = n;
	for (int i = 0; i + 1 < a.size(); ++i) {
		if (a[i + 1] - a[i] - 1 != 0) {
			k = min(k, a[i + 1] - a[i] - 1);
		}
	}
	for (int i = 0; i + 1 < a.size(); ++i) {
		if (a[i + 1] != a[i]) {
			ans += (a[i + 1] - a[i] - 1 + k - 1) / k;
		}
	}

	cout << ans << '\n';

	return 0;
}
