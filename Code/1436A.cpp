#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		long long sum = 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (int i : a) {
			sum += i;
		}

		if (sum == m) {
			cout <<"YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
