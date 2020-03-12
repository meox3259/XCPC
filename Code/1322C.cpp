#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<long long> c;
		c.resize(n);
		vector<vector<int> > g;
		vector<vector<int> > rev;
		g.resize(n);
		rev.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		vector<long long> sum;
		for(int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			g[v].emplace_back(u);
		}
		map<vector<int>, long long> mp;
		for(int i = 0; i < n; ++i) {
			sort(g[i].begin(), g[i].end());
		}
		for(int i = 0; i < n; ++i) {
			if(!g[i].empty()) {
				mp[g[i]] += c[i];
			}
		}
		long long ans = 0;
		for(auto &x : mp) {
			ans = __gcd(ans, x.second);
		}
		cout << ans << '\n';
	}
	return 0;
}
