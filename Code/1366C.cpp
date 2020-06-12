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

		vector<int> cnt0(n + m + 1);
		vector<int> cnt1(n + m + 1);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(a[i][j] == 0) {
					cnt0[i + j] += 1;
				} else {
					cnt1[i + j] += 1;
				}
			}
		}

		int ans = 0;
		for(int i = 0; i + i < n + m - 2; ++i) {
			int c0 = cnt0[i] + cnt0[n + m - 2 - i];
			int c1 = cnt1[i] + cnt1[n + m - 2 - i];

			ans += min(c0, c1);
		}

		cout << ans << '\n';
	}

	return 0;
}
