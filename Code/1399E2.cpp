#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long S;
		cin >> n >> S;

		vector<vector<tuple<int, int, int> > > G(n);
		for(int i = 0; i < n - 1; ++i) {
			int u, v, w, c;
			cin >> u >> v >> w >> c;
			--u; --v; --c;
			G[u].emplace_back(v, w, c);
			G[v].emplace_back(u, w, c);
		}

		vector<multiset<tuple<long long, long long, long long> > > s(2);

		long long sum = 0;
		vector<int> leaf(n);
		function<void(int, int)> dfs = [&] (int u, int f) {
			if(G[u].size() == 1) {
				leaf[u] = 1;
			}
			for(auto [v, w, c] : G[u]) {
				if(v != f) {
					dfs(v, u);
					leaf[u] += leaf[v];
					s[c].emplace(1LL * (w + 1) / 2 * leaf[v], w / 2, leaf[v]);
					sum += 1LL * leaf[v] * w;
				}
			}
		};

		dfs(0, -1);	

		int ans = 0;
		while(sum > S) {
			if(s[0].empty()) {
				auto [d1, w1, l1] = *s[1].rbegin();
				s[1].erase(--s[1].end());
				sum -= d1;
				ans += 2;
				s[1].emplace((w1 + 1) / 2 * l1, w1 / 2, l1);
			} else if(s[1].empty()) {
				auto [d0, w0, l0] = *s[0].rbegin();
				s[0].erase(--s[0].end());
				sum -= d0;
				ans += 1;
				s[0].emplace((w0 + 1) / 2 * l0, w0 / 2, l0);
			} else {
				auto [d1, w1, l1] = *s[1].rbegin();
				auto [d00, w00, l00] = *s[0].rbegin();
				s[0].erase(--s[0].end());
				s[0].emplace((w00 + 1) / 2 * l00, w00 / 2, l00);
				auto [d01, w01, l01] = *s[0].rbegin();
				if(S + d00 >= sum) {
					ans += 1;
					break;
				}
				long long tmp = d00 + d01;
				if(tmp <= d1) {
					sum -= d1;
					ans += 2;
					s[0].erase(s[0].find({(w00 + 1) / 2 * l00, w00 / 2, l00}));
					s[0].emplace(d00, w00, l00);
					s[1].erase(--s[1].end());
					s[1].emplace((w1 + 1) / 2 * l1, w1 / 2, l1);
				} else {
					sum -= d00;
					ans += 1;
				}
			}
		} 

		cout << ans << '\n';
	}

	return 0;
}
