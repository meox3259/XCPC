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

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if((i + j) & 1) {
					if(a[i][j] % 2 == 0) {
						a[i][j] += 1;
					}	
				} else {
					if(a[i][j] % 2 == 1) {
						a[i][j] += 1;
					}
				}
			}
		}

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cout << a[i][j] << " \n"[j == m - 1];
			}
		}
	}

	return 0;
}
