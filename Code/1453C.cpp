#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
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

		vector<vector<int> > row(n, vector<int> (10));
		vector<vector<int> > col(n, vector<int> (10));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				row[i][a[i][j]] = 1;
				col[j][a[i][j]] = 1;
			}
		}

		for (int d = 0; d < 10; ++d) {
			int ans = 0;	
			for (int i = 0; i < n; ++i) {
				vector<int> pos;
				for (int j = 0; j < n; ++j) {
					if (a[i][j] == d) {
						pos.emplace_back(j);
					}
				} 

				if (pos.empty()) {
					continue;
				}

				int left = i;
				int right = i;

				for (int j = 0; j < i; ++j) {
					if (row[j][d]) {
						left = j;
						break;
					}
				}

				for (int j = n - 1; j > i; --j) {
					if (row[j][d]) {
						right = j;
						break;
					}
				}

				int h = max(i - left, right - i);

				for (int j : pos) {
					int low = max(j, n - j - 1);
					ans = max(ans, h * low);
				}

				if (pos.size() > 1) {
					int low = pos.back() - pos[0];	
					int h = max(i, n - i - 1);
					ans = max(ans, h * low);
				}
			}

			for (int j = 0; j < n; ++j) {
				vector<int> pos;
				for (int i = 0; i < n; ++i) {
					if (a[i][j] == d) {
						pos.emplace_back(i);
					}
				} 

				if (pos.empty()) {
					continue;
				}

				int left = j;
				int right = j;

				for (int i = 0; i < j; ++i) {
					if (col[i][d]) {
						left = i;
						break;
					}
				}

				for (int i = n - 1; i > j; --i) {
					if (col[i][d]) {
						right = i;
						break;
					}
				}

				int h = max(j - left, right - j);

				for (int i : pos) {
					int low = max(i, n - i - 1);
					ans = max(ans, h * low);
				}

				if (pos.size() > 1) {
					int low = pos.back() - pos[0];	
					int h = max(j, n - j - 1);
					ans = max(ans, h * low);
				}
			}

			cout << ans << " \n"[d == 9];
		}
	}
	
	return 0;
}
