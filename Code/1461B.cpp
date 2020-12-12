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

		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		vector<vector<int> > l(n, vector<int> (m));
		vector<vector<int> > r(n, vector<int> (m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (j == 0) {
					l[i][j] = (s[i][j] == '*');
				} else {
					if (s[i][j] == '.') {
						l[i][j] = 0;
					} else {
						l[i][j] = l[i][j - 1] + 1;
					}
				}
			}	
			for (int j = m - 1; j >= 0; --j) {
				if (j == m - 1) {
					r[i][j] = (s[i][j] == '*');
				} else {
					if (s[i][j] == '.') {
						r[i][j] = 0; 
					} else {
						r[i][j] = r[i][j + 1] + 1;
					}
				}
			}
		}

		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = i; k < n; ++k) {
					if (l[k][j] < k - i + 1 || r[k][j] < k - i + 1) {
						break;
					}
					ans ++;
				}	
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
