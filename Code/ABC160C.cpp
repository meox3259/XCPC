#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n;
	cin >> k >> n;

	vector<long long> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long ans = k;

	for(int i = 0; i + 1 < n; ++i) {
		ans = min(ans, k - (a[i + 1] - a[i]));
	}

	ans = min(ans, k - (k - a.back() + a[0]));

	cout << ans << '\n';

	return 0;
}
