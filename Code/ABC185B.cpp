#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;

	vector<int> a(m);
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
	}

	long long sum = n;
	bool ok = true;
	a.emplace_back(t);
	b.emplace_back(t);
	for (int i = 0; i <= m; ++i) {
		sum -= a[i] - (i == 0 ? 0 : b[i - 1]);
		if (sum <= 0) {
			ok = false;
		}
		sum += b[i] - a[i];
		sum = min(sum, 1LL * n);
	}

	if (ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
