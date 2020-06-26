#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> w(n);
	for(int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	vector<vector<pair<int, int> > > G(n);
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y, i);
		G[y].emplace_back(x, i);
		--w[x]; --w[y];
	}

	queue<int> q;
	for(int i = 0; i < n; ++i) {
		if(w[i] >= 0) {
			q.emplace(i);
		}
	}

	vector<int> ans;
	vector<bool> vis(m);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto [v, x] : G[u]) {
			if(!vis[x]) {
				vis[x] = true;
				w[v] += 1;
				ans.emplace_back(x);
				if(w[v] == 0) {
					q.emplace(v);
				}
			}
		}
	}

	if(ans.size() != m) {
		cout << "DEAD" << '\n';
	} else {
		reverse(ans.begin(), ans.end());
		cout << "ALIVE" << '\n';
		for(int i : ans) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
