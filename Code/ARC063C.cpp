#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > G;
	vector<int> ans;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	G.resize(n);
	ans.assign(n, inf);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int k;
	cin >> k;
	while(k--) {
		int x, y;
		cin >> x >> y;
		--x;
		ans[x] = y;
		q.emplace(y, x);
	}
	while(!q.empty()) {
		auto o = q.top();
		q.pop();
		int u = o.second;
		for(auto v : G[u]) {
			if(ans[v] == inf) {
				ans[v] = ans[u] + 1;
				q.emplace(ans[v], v);
			}
			if(abs(ans[v] - ans[u]) != 1) {
				cout << "No" << '\n';
				return 0;
			}
		}
	}
	cout << "Yes" << '\n';
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}
