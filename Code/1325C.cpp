#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vector<pair<int, int> > e;
	vector<vector<int> > G;
	G.resize(n);

	vector<int> d;
	d.resize(n);

	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		if(u > v) {
			swap(u, v);
		}
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		e.emplace_back(u, v);
		++d[u];
		++d[v];
	}

	int mx = *max_element(d.begin(), d.end());

	map<pair<int, int>, int> ans;

	int p = 0;

	for(int i = 0; i < n; ++i) {
		if(d[i] == mx) {
			for(auto v : G[i]) {
				ans[minmax(v, i)] = p++;
			}
			break;
		}
	}

	for(auto& x : e) {
		if(ans.count(x)) {
			cout << ans[x] << '\n'; 
		} else {
			cout << p++ << '\n';
		}
	}
	return 0;
}
