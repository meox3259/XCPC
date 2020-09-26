#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > G(n);
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}

	vector<bool> vis(n);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			queue<int> q;
			q.emplace(i);
			vis[i] = true;
			ans += 1;
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				for(int v : G[u]) {
					if(!vis[v]) {
						q.emplace(v);
						vis[v] = true;
					}
				}
			}
		}
	}

	cout << ans - 1 << '\n';

	return 0;
}
