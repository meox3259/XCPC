#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while(q--) {
		int n, m;
		cin >> n >> m;

		vector<string> s(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		vector<int> row(n);
		vector<int> col(m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(s[i][j] == '.') {
					row[i] += 1;
					col[j] += 1;
				}	
			}
		}

		int ans = n * m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				ans = min(ans, row[i] + col[j] - (s[i][j] == '.'));
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
