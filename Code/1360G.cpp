#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		vector<vector<int> > ans(n, vector<int> (m));
		vector<int> col(m);

		bool ok = true;

		for(int i = 0; i < n; ++i) {
			int cnt = 0;
			vector<int> id(m, 0);
			iota(id.begin(), id.end(), 0);
			sort(id.begin(), id.end(), [&] (int i, int j) {
				return col[i] < col[j];
			});
			for(int j : id) {
				if(col[j] < b && cnt < a) {
					cnt += 1;
					col[j] += 1;
					ans[i][j] = 1;
				}
			}
			if(cnt != a) {
				ok = false;
			}
		}

		for(int i = 0; i < m; ++i) {
			if(col[i] != b) {
				ok = false;
			}
		}

		if(ok) {
			cout << "YES" << '\n';
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					cout << ans[i][j];
				}
				cout << '\n';
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
