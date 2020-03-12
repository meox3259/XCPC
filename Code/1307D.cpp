#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> p;
	p.resize(k);
	for(int i = 0; i < k; ++i) {
		cin >> p[i];
		--p[i];
	}
	vector<vector<int> > G;
	G.resize(n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	queue<int> q;
	q.emplace(0);
	vector<int> a;
	a.resize(n, -1);
	a[0] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(a[v] == -1) {
				a[v] = a[u] + 1;
				q.emplace(v);
			}
		}
	}
	q.emplace(n - 1);
	vector<int> b;
	b.resize(n, -1);
	b[n - 1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(b[v] == -1) {
				b[v] = b[u] + 1;
				q.emplace(v);
			}
		}
	}
	sort(p.begin(), p.end(), [&] (int i, int j) {
		return a[i] < a[j];
	});
	int mx = -n;
	int tmp = 0;
	for(int i = k - 1; i >= 0; --i) {
		tmp = max(tmp, a[p[i]] + mx + 1);
		mx = max(mx, b[p[i]]);
	}
	cout << min(b[0], tmp) << '\n';
	return 0;
}
