#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > G;
	G.resize(n);

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;

		--u;
		--v;

		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> dep;
	dep.resize(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		for(int v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] + 1;
				dfs(v, u);
			}
		}
	};

	dfs(0, -1);

	bool odd = false;
	bool even = false;

	for(int i = 0; i < n; ++i) {
		if(G[i].size() == 1) {
			if(dep[i] & 1) {
				odd = true;
			} else {
				even = true;
			}
		}
	}

	int low;

	if(odd && even) {
		low = 3;
	} else {
		low = 1;
	}

	int high = n - 1;

	for(int i = 0; i < n; ++i) {
		int cnt = 0;

		for(int j : G[i]) {
			if(G[j].size() == 1) {
				++cnt;
			}
		}

		if(cnt > 0) {
			high -= cnt - 1;
		}
	}

	cout << low << ' ' << high << '\n';

	return 0;
}
