#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > a(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector<pair<int, int> > ans;
	vector<vector<int> > b(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i + 1 < n && j + 1 < m && a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
				b[i][j] = 1;
				b[i + 1][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j + 1] = 1;
				ans.emplace_back(i, j);
			}
		}
	}

	if (a != b) {
		cout << -1 << '\n';
	} else {
		cout << ans.size() << '\n';
		for (auto [x, y] : ans) {
			cout << x + 1 << ' ' << y + 1 << '\n';
		}
	}

	return 0;
}
