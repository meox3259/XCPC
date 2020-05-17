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

	vector<bool> vis(n);
	vector<int> sign(n);

	queue<int> q;
	q.emplace(0);
	vis[0] = true;

	int cnt = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		++cnt;

		for(int v : G[u]) {
			if(!vis[v]) {
				vis[v] = true;
				q.emplace(v);
				sign[v] = u;
			}
		}
	}

	if(cnt != n) {
		cout << "No" << '\n';
	} else {
		cout << "Yes" << '\n';
		for(int i = 1; i < n; ++i) {
			cout << sign[i] + 1 << '\n';
		}
	}

	return 0;
}
