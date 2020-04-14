#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;

			--i;
		}

		vector<vector<int> > p;
		p.resize(200);

		for(int i = 0; i < n; ++i) {
			p[a[i]].emplace_back(i);
		}

		vector<vector<int> > sum;
		sum.resize(n);
		
		for(int i = 0; i < n; ++i) {
			sum[i].resize(200);
		}

		sum[0][a[0]] = 1;

		for(int i = 0; i + 1 < n; ++i) {
			sum[i + 1] = sum[i];

			++sum[i + 1][a[i + 1]];
		}

		int ans = 0;

		for(int i = 0; i < 200; ++i) {
			int m = p[i].size();

			ans = max(ans, m);

			for(int j = 0; m - 1 - j > j && j < m; ++j) {
				int l = p[i][j];
				int r = p[i][m - 1 - j];

				int tmp = (j + 1) * 2; 

				for(int k = 0; k < 200; ++k) {
					if(k != i) {
						ans = max(ans, tmp + sum[r][k] - sum[l][k]);
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
