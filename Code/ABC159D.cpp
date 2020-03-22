#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	a.resize(n);

	vector<int> sum;
	sum.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];

		--a[i];

		++sum[a[i]];
	}

	long long ans = 0;

	for(int i = 0; i < n; ++i) {
		ans += 1LL * sum[i] * (sum[i] - 1) / 2;
	}

	for(int i = 0; i < n; ++i) {
		long long tmp = ans;

		tmp -= 1LL * sum[a[i]] * (sum[a[i]] - 1) / 2;
		tmp += 1LL * (sum[a[i]] - 1) * (sum[a[i]] - 2) / 2;

		cout << tmp << '\n';
	}

	return 0;
}
