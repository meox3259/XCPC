#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<int> row(n);
		for (int i = 0; i < n; ++i) {
			cin >> row[i];
		}

		vector<int> col(m);
		for (int i = 0; i < m; ++i) {
			cin >> col[i];
		}

		set<int> s;
		for (int i : row) {
			s.emplace(i);
		}

		for (int i : col) {
			s.emplace(i);
		}

		cout << n + m - s.size() << '\n'; 
	}

	return 0;
}
