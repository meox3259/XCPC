#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long ans = 0;

	for(int i = 0; i < n - 1; ++i) {
		int d = max(a[i] + a[i + 1] - x, 0);

		ans += d;
		a[i + 1] -= min(a[i + 1], d);
	}

	cout << ans << '\n';
	return 0;
}
