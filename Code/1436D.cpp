#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > adj(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		adj[p - 1].emplace_back(i);
	}

	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long ans = 0;
	vector<int> leaves(n);
	auto dfs = [&] (auto &&f, int x) -> void {
		leaves[x] = adj[x].empty();
		for (int y : adj[x]) {
			f(f, y);
			a[x] += a[y];
			leaves[x] += leaves[y];
		}
		ans = max(ans, (a[x] - 1 + leaves[x]) / leaves[x]);
	};

	dfs(dfs, 0);

	cout << ans << '\n';

	return 0;
}
