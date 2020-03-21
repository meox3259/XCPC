#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while(T--) {
		int n;
		cin >> n;

		vector<vector<int> > G;
		G.resize(n);

		for(int i = 0; i < n - 1; ++i) {
			int u, v, w;
			cin >> u >> v >> w;

			--u;
			--v;

			G[u].emplace_back(w);
			G[v].emplace_back(w);
		}

		for(int i = 0; i < n; ++i) {
			sort(G[i].begin(), G[i].end());
		}

		long long ans = 0;

		for(int i = 0; i < n; ++i) {
			for(int j = 1; j < G[i].size(); ++j) {
				ans += *G[i].begin() + G[i][j];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
