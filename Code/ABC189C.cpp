#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = a[i];
		for (int j = i; j < n; ++j) {
			cur = min(cur, a[j]);
			ans = max(ans, cur * (j - i + 1));
		}
	}

	cout << ans << '\n';

	return 0;
}
