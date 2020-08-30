#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > G(n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	vector<bool> vis(n);

	int ans = 0;
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			int cnt = 0;
			queue<int> q;
			q.emplace(i);
			vis[i] = true;
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				cnt += 1;
				for(int v : G[u]) {
					if(!vis[v]) {
						vis[v] = true;
						q.emplace(v);
					}
				}
			}
			ans = max(ans, cnt);
		}
	}

	cout << ans << '\n';

	return 0;
}
