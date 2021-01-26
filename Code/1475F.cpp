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

		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		vector<vector<int> > a(n, vector<int> (n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = s[i][j] - '0';
			}
		}

		vector<string> t(n);
		for (int i = 0; i < n; ++i) {
			cin >> t[i];
		}

		vector<vector<int> > b(n, vector<int> (n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = t[i][j] - '0';
			}
		}

		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				int x = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
				int y = b[i][j] + b[i + 1][j] + b[i][j + 1] + b[i + 1][j + 1];
				if (x % 2 != y % 2) {
					ok = false;
				}
			}
		}

		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
