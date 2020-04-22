#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		--a;
		--b;
		--c;

		vector<vector<int> > G;
		G.resize(n);

		function<void(int, vector<int> &)> bfs = [&] (int s, vector<int> &d) {
			d.assign(n, -1);
			d[s] = 0;

			queue<int> q;
			q.emplace(s);
			
			while(!q.empty()) {
				int u = q.front();
				q.pop();

				for(int v : G[u]) {
					if(d[v] == -1) {
						d[v] = d[u] + 1;
						q.emplace(v);
					}
				}
			}
		};

		vector<int> p;
		p.resize(m);

		for(int &i : p) {
			cin >> i;
		}

		for(int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;

			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}

		vector<int> da;
		da.resize(n);

		vector<int> db;
		db.resize(n);

		vector<int> dc;
		dc.resize(n);

		bfs(a, da);
		bfs(b, db);
		bfs(c, dc);

		sort(p.begin(), p.end());

		vector<long long> pre;
		pre.resize(m);

		pre[0] = p[0];
		for(int i = 0; i < m - 1; ++i) {
			pre[i + 1] = pre[i] + p[i + 1];
		}

		long long ans = inf;

		for(int i = 0; i < n; ++i) {
			if(da[i] + db[i] + dc[i] <= m) {
				long long tmp = 0;
				tmp += db[i] > 0 ? pre[db[i] - 1] : 0;
				tmp += da[i] + db[i] + dc[i] > 0 ? pre[min(da[i] + db[i] + dc[i] - 1, m - 1)] : 0;

				ans = min(ans, tmp);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
