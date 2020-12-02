#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> suf(n);
	suf[n - 1] = a[n - 1];
	for (int i = n - 1; i >= 1; --i) {
		suf[i - 1] = suf[i] + a[i - 1];
	}

	sort(suf.begin() + 1, suf.end(), greater<long long> ());
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += suf[i];
	}

	cout << ans << '\n';

	return 0;
}
