#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G(n);
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}

	vector<int> dep(n);
	function<void(int, int)> dfs = [&] (int u, int f) {
		for(int v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] + 1;
				dfs(v, u);
			}
		}
	};

	dfs(0, -1);

	int mx = *max_element(dep.begin(), dep.end());
	int s = -1;

	for(int i = 0; i < n; ++i) {
		if(dep[i] == mx) {
			s = i;
			break;
		}
	}

	dep[s] = 0;
	dfs(s, -1);

	int m = *max_element(dep.begin(), dep.end()) + 1;
	vector<int> dp(m + 1);
	dp[1] = 1;
	for(int i = 1; i <= m; ++i) {
		if(i + 1 <= m) {
			dp[i + 1] |= !dp[i];
		}
		if(i + 2 <= m) {
			dp[i + 2] |= !dp[i];
		}
	}

	if(dp[m]) {
		cout << "First" << '\n';
	} else {
		cout << "Second" << '\n';
	}

	return 0;
}
