#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> s(n);
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	vector<int> col(n, -1);
	bool ok = true;

	function<void(int, int)> dfs = [&] (int u, int cur) {
		col[u] = cur;
		for(int v = 0; v < n; ++v) {
			if(s[u][v] == '1') {
				if(col[v] != -1) {
					if(col[v] == col[u]) {
						ok = false;
					}			
				} else {
					dfs(v, cur ^ 1);
				}
			}
		}
	};

	dfs(0, 0);

	if(!ok) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<vector<int> > d(n, vector<int> (n));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			d[i][j] = (s[i][j] == '0' ? n : 1);
		}
	}

	for(int i = 0; i < n; ++i) {
		d[i][i] = 0;
	}

	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans + 1 << '\n';

	return 0;
}
