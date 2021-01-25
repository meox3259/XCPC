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

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int sum = 0;
		for (int i : a) {
			sum += i;
		}

		vector<int> cnt(2);
		for (int i : a) {
			cnt[i - 1] ++;
		}

		if (sum % 2 != 0 || ((sum / 2) % 2 != 0 && cnt[0] < 2)) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}
