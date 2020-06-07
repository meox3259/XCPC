#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > G(n);

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> t(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	vector<bool> vis(n + 1, false);

	for(int u = 0; u < n; ++u) {
		vis[0] = true;
		for(int i : G[u]) {
			vis[t[i]] = true;
		}
		int cur = 0;
		while(vis[cur]) {
			++cur;
		}
		if(cur != t[u]) {
			cout << -1 << '\n';
			exit(0);
		}
		for(int i : G[u]) {
			vis[t[i]] = false;
		}
	}

	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 0);
	auto cmp = [&] (int i, int j) {
		return t[i] < t[j];
	};
	sort(ans.begin(), ans.end(), cmp);

	for(int i : ans) {
		cout << i + 1 << ' ';
	}
	cout << '\n';

	return 0;
}
