#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a;
	vector<int> vis;
	vector<int> hv;
	a.resize(m);
	hv.assign(1 << n, 0);
	vis.assign(1 << n + 1, 0);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
		hv[a[i]] = 1;
	}
	function<void(int)> dfs = [&] (int u) {
		if(vis[u]) {
			return;
		}
		vis[u] = 1;
		if(u < (1 << n)) {
			if(hv[u]) {
				dfs(u + (1 << n));
			}		
		} else {
			dfs((u - (1 << n)) ^ ((1 << n) - 1));
			for(int i = 0; i < n; ++i) {
				if(!(u >> i & 1)) {
					dfs(u ^ (1 << i));
				}
			}
		}
	};
	int ans = 0;
	for(int i = 0; i < m; ++i) {
		if(!vis[a[i]]) {
			++ans;
			dfs(a[i]);
		}
	}
	cout << ans << '\n';
	return 0;
}
