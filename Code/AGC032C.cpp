#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> d(n);
	vector<vector<int> > G(n);
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
		d[x] += 1;
		d[y] += 1;
	}

	int big = 0;
	int four = 0;
	int two = 0;
	bool odd = false;
	for(int i = 0; i < n; ++i) {
		if(d[i] == 2) {
			two += 1;
		}
		if(d[i] == 4) {
			four += 1;
		}
		if(d[i] % 2 == 1) {
			odd = true;
		}
		if(d[i] > 4) {
			big += 1;
		}
	}

	if(odd) {
		cout << "No" << '\n';
		exit(0);
	}

	vector<bool> vis(n);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		for(int v : G[u]) {
			if(!vis[v]) {
				dfs(v);
			}
		}
	}; 

	if(big == 0) {
		if(four > 2) {
			cout << "Yes" << '\n';
		} else if(four < 2) {
			cout << "No" << '\n';
		} else {
			vector<int> node;
			for(int i = 0; i < n; ++i) {
				if(d[i] == 4) {
					node.emplace_back(i);
				}
			}
			vis[node[0]] = true;
			dfs(node[1]);
			int cnt = 0;
			for(int i = 0; i < n; ++i) {
				if(vis[i]) {
					cnt += 1;
				}
			}
			if(cnt == n) {
				cout << "No" << '\n';
			} else {
				cout << "Yes" << '\n';
			}
		}
	} else {
		cout << "Yes" << '\n';
	}

	return 0;
}
