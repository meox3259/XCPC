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

		vector<vector<int> > G(n);
		for (int i = 0; i < n - 1; ++i) {	
			int x, y;
			cin >> x >> y;
			--x; --y;
			G[x].emplace_back(y);
			G[y].emplace_back(x);
		}

		vector<int> dep(n);
		vector<int> par(n);
		vector<int> low(n);
		function<void(int, int)> pre_dfs = [&] (int x, int f) {
			par[x] = f;
			if (G[x].size() == 1) {
				low[x] = dep[x];
			} else {
				low[x] = n;
			}
			for (int y : G[x]) {
				if (y != f) {
					dep[y] = dep[x] + 1;
					pre_dfs(y, x);
					low[x] = min(low[x], low[y]);
				}
			}
		};

		pre_dfs(0, -1);

		int l = 0;
		int r = n + 1;

		auto check = [&] (int k) {
			bool ok = true;
			function<void(int, int, int)> dfs = [&] (int x, int f, int depth) {
				if (dep[x] - depth > k) {
					ok = false;
				}
				if (x != 0) {
					sort(G[x].begin(), G[x].end(), [&] (int i, int j) {
						return low[i] > low[j];
					});
				} else {
					sort(G[x].begin(), G[x].end(), [&] (int i, int j) {
						return low[i] < low[j];
					});
				}
				int cnt = 0;
				for (int y : G[x]) {
					if (y != f) {
						cnt ++;
					}	
				}
				for (int y : G[x]) {
					if (y != f) {
						cnt --;
						if (cnt == 0) {
							dfs(y, x, depth);
						} else {
							dfs(y, x, dep[x] - 1);
						}
					}
				}
			};

			dfs(0, -1, 0);

			return ok;
		};

		while (r - l > 1) {
			int mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		cout << r << '\n';
	}

	return 0;
}
