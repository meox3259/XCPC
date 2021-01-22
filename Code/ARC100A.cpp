#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long l = -1000000000;
	long long r = 1000000000;

	auto calc = [&] (long long b) {
		long long ret = 0;
		for (int i = 0; i < n; ++i) {
			ret += abs(a[i] - b - i - 1);
		}
		return ret;
	};

	long long ans = numeric_limits<long long>::max();

	while (r - l > 2) {
		long long lmid = (l + l + r) / 3;
		long long rmid = (l + r + r) / 3;
		if (calc(lmid) < calc(rmid)) {
			r = rmid;
		} else {
			l = lmid;
		}
	}

	for (long long i = l; i <= r; ++i) {
		ans = min(ans, calc(i));
	}

	cout << ans << '\n';

	return 0;
}
