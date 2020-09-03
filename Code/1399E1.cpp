#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long s;
		cin >> n >> s;

		vector<vector<pair<int, int> > > G(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			--u; --v;
			G[u].emplace_back(v, w);
			G[v].emplace_back(u, w);
		}

		priority_queue<tuple<long long, long long, long long> > q;

		long long sum = 0;
		vector<int> leaf(n);
		function<void(int, int)> dfs = [&] (int u, int f) {
			if(G[u].size() == 1) {
				leaf[u] = 1;
			}
			for(auto [v, w] : G[u]) {
				if(v != f) {
					dfs(v, u);
					leaf[u] += leaf[v];
					q.emplace(1LL * leaf[v] * (w + 1) / 2, w, leaf[v]);
					sum += 1LL * leaf[v] * w;
				}
			}
		};

		dfs(0, -1);

		int ans = 0;
		while(sum > s) {
			auto [d, w, l] = q.top();
			q.pop();
			sum -= 1LL * (w + 1) / 2 * l;
			w /= 2;
			q.emplace((w + 1) / 2 * l, w, l);
			ans += 1;
		}

		cout << ans << '\n';
	}

	return 0;
}
