#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<pair<int, int> > > edge(200001);
	for(int i = 0; i < n - 1; ++i) {
		int x, y, w;
		cin >> x >> y;
		--x; --y;
		w = __gcd(a[x], a[y]);
		edge[w].emplace_back(x, y);
		for(int j = 2; j * j <= w; ++j) {
			if(w % j == 0) {
				edge[j].emplace_back(x, y);
				while(w % j == 0) {
					w /= j;
				}
			}
		}
		if(w > 1) {
			edge[w].emplace_back(x, y);
		}
	}

	if(*max_element(a.begin(), a.end()) == 1) {
		cout << 0 << '\n';
		exit(0);
	}

	int ans = 0;
	vector<bool> vis(n);
	vector<vector<int> > G(n);
	vector<int> d(n);
	for(int i = 2; i <= 200000; ++i) {
		vector<int> node;
		for(auto [x, y] : edge[i]) {
			node.emplace_back(x);
			node.emplace_back(y);
		}
		sort(node.begin(), node.end());
		node.erase(unique(node.begin(), node.end()), node.end());
		for(int x : node) {
			vis[x] = false; 
		}
		for(int x : node) {
			G[x].clear();
		}
		for(int x : node) {
			d[x] = -1;
		}
		for(auto [x, y] : edge[i]) {
			G[x].emplace_back(y);
			G[y].emplace_back(x);
		}
		auto bfs = [&] (int s) {
			queue<int> q;	
			d[s] = 0;
			q.emplace(s);
			vector<int> tmp;
			while(!q.empty()) {
				int u = q.front();
				vis[u] = true;
				q.pop();
				tmp.emplace_back(u);
				for(int v : G[u]) {
					if(d[v] == -1) {
						d[v] = d[u] + 1;
						q.emplace(v);
					}
				}
			}
			int cur = s;
			for(int x : tmp) {
				if(d[x] > d[cur]) {
					cur = x;
				}
			}
			for(int x : tmp) {
				d[x] = -1;
			}
			d[cur] = 0;
			q.emplace(cur);
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
			int ret = 0;
			for(int x : tmp) {
				ret = max(ret, d[x]);
			} 
			return ret;
		};
		for(int x : node) {
			if(!vis[x]) {
				ans = max(ans, bfs(x));
			}	
		}
	}

	cout << ans + 1 << '\n';

	return 0;
}
