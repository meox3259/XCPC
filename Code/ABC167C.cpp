#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	vector<int> c(n);
	vector<vector<int> > a(n, vector<int> (m));

	for(int i = 0; i < n; ++i) {
		cin >> c[i];
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int ans = inf;

	for(int i = 0; i < 1 << n; ++i) {
		vector<int> sum(m);
		for(int j = 0; j < n; ++j) {
			if(i >> j & 1) {
				for(int k = 0; k < m; ++k) {
					sum[k] += a[j][k];
				}
			}
		}
		int tmp = 0;
		for(int j = 0; j < n; ++j) {
			if(i >> j & 1) {
				tmp += c[j];
			}
		}
		if(*min_element(sum.begin(), sum.end()) >= x) {
			ans = min(ans, tmp);
		}
	}

	if(ans == inf) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
