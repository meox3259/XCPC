#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;

	vector<vector<int> > G;
	G.resize(n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}
	
	vector<int> dep;
	dep.resize(n);

	function<void(int, int)> dfs = [&] (int u, int f) {
		for(auto v : G[u]) {
			if(v != f) {
				dep[v] = dep[u] ^ 1;
				dfs(v, u);
			}
		}	
	};

	dfs(0, -1);
	
	return 0;
}
