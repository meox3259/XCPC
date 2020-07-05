#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int> > a(n, vector<int> (m));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}

		bool ok = true;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
					if(a[i][j] > 2) {
						ok = false;
					}
				} else if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					if(a[i][j] > 3) {
						ok = false;
					}
				} else {
					if(a[i][j] > 4) {
						ok = false;
					}
				}
			}
		}

		if(!ok) {
			cout << "NO" << '\n';
			continue;
		}

		cout << "YES" << '\n';
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
					cout << 2 << ' ';
				} else if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					cout << 3 << ' ';
				} else {
					cout << 4 << ' ';
				}
			}

			cout << '\n';
		}
	}

	return 0;
}
