#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<vector<int> > a(n, vector<int> (n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	vector<vector<bool> > col(n, vector<bool> (n, true));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int i = 0; i < n; ++i) {
				if (a[i][x] + a[i][y] > k) {
					col[x][y] = false;
				}
			}
		}
	}

	vector<vector<bool> > row(n, vector<bool> (n, true));
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int i = 0; i < n; ++i) {
				if (a[x][i] + a[y][i] > k) {
					row[x][y] = false;
				}
			}
		}
	}

	vector<long long> fac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i % P;
	}

	auto calc = [&] (vector<vector<bool> > a) {
		vector<bool> vis(n);
		long long ret = 1;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				int cnt = 0;
				queue<int> q;
				q.emplace(i);
				vis[i] = true;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					cnt ++;
					for (int y = 0; y < n; ++y) {
						if (a[x][y] && !vis[y]) {
							q.emplace(y);
							vis[y] = true;
						}
					}
				}
				ret = ret * fac[cnt] % P;
			}
		}
		return ret;
	};

	cout << calc(col) * calc(row) % P << '\n';

	return 0;
}
