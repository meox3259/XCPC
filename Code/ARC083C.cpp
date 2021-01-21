#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
const int inf = numeric_limits<int>::max() / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		p --;
		G[p].emplace_back(i);
	}

	vector<int> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	bool ok = true;
	function<pair<int, int>(int)> dfs = [&] (int u) {
		vector<pair<int, int> > obj;
		for (int v : G[u]) {
			obj.emplace_back(dfs(v));
		}
		
		vector<int> dp(x[u] + 1, inf);
		dp[0] = 0;
		for (auto [a, b] : obj) {
			vector<int> tmp(x[u] + 1, inf);
			for (int i = x[u]; i >= a; --i) {
				tmp[i] = min(tmp[i], dp[i - a] + b);
			}
			for (int i = x[u]; i >= b; --i) {
				tmp[i] = min(tmp[i], dp[i - b] + a);
			}
			swap(dp, tmp);
		}

		int Min = *min_element(dp.begin(), dp.end());
		if (Min == inf) {
			ok = false;
		}

		return make_pair(x[u], Min);
	};

	dfs(0);

	if (ok) {
		cout << "POSSIBLE" << '\n';
	} else {
		cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}
