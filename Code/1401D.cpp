#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<vector<int> > G(n);
		for(int i = 0; i < n - 1; ++i) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			G[x].emplace_back(y);
			G[y].emplace_back(x);
		}

		vector<int> sz(n);
		vector<long long> edge;
		function<void(int, int)> dfs = [&] (int u, int f) {
			sz[u] = 1;
			for(int v : G[u]) {
				if(v != f) {
					dfs(v, u);
					sz[u] += sz[v];
					edge.emplace_back(1LL * sz[v] * (n - sz[v]));
				}
			}
		};

		dfs(0, -1);
		
		sort(edge.begin(), edge.end());

		int m;
		cin >> m;

		vector<long long> p(m);
		for(int i = 0; i < m; ++i) {
			cin >> p[i];
		}

		while(p.size() < n - 1) {
			p.emplace_back(1);
		}

		sort(p.begin(), p.end());

		while(p.size() > n - 1) {
			long long x = p.back();
			p.pop_back();
			p.back() = p.back() * x % P;
		}

		long long ans = 0;
		for(int i = 0; i < n - 1; ++i) {
			ans = (ans + p[i] * edge[i]) % P;
		}

		cout << ans << '\n';
	}

	return 0;
}
