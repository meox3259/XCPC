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

		vector<bool> black;
		black.resize(n * m);

		for(int i = 0; i < n; ++i) {
			string s;
			cin >> s;

			for(int j = 0; j < m; ++j) {
				if(s[j] == '0') {
					black[i * m + j] = true;
				}
			}
		}

		vector<vector<int> > G;
		G.resize(n * m);

		for(int i = 0; i < n; ++i) {
			string dir;
			cin >> dir;

			for(int j = 0; j < m; ++j) {
				int x = i * m + j;

				if(dir[j] == 'U') {
					G[x].emplace_back((i - 1) * m + j);
				}

				if(dir[j] == 'D') {
					G[x].emplace_back((i + 1) * m + j);
				}

				if(dir[j] == 'L') {
					G[x].emplace_back(i * m + j - 1);
				}

				if(dir[j] == 'R') {
					G[x].emplace_back(i * m + j + 1);
				}
			}
		}

		vector<int> deg;
		deg.resize(n * m);

		for(int i = 0; i < n * m; ++i) {
			for(int j : G[i]) {
				++deg[j];
			}
		}

		queue<int> q;

		for(int i = 0; i < n * m; ++i) {
			if(deg[i] == 0) {
				q.emplace(i);
			}
		}

		vector<bool> vis;
		vis.resize(n * m);

		while(!q.empty()) {
			int u = q.front();
			q.pop();

			vis[u] = true;

			for(int v : G[u]) {
				if(!--deg[v]) {
					q.emplace(v);
				}
			}
		}

		vector<vector<int> > node;
		node.resize(n * m);
		
		int ans1 = 0;

		for(int i = 0; i < n * m; ++i) {
			if(!vis[i]) {
				++ans1;
			}
		}
		
		vector<bool> mark = vis;

		vector<vector<int> > rev;
		rev.resize(n * m);

		for(int i = 0; i < n * m; ++i) {
			for(int j : G[i]) {
				rev[j].emplace_back(i);
			}
		}

		function<void(int, int, int, vector<int> &, int)> dfs = [&] (int u, int d, int D, vector<int> &tmp, int mo) {
			if(black[u]) {
				tmp.emplace_back((d + D) % mo);
			}

			for(int v : rev[u]) {
				if(mark[v]) {
					dfs(v, d + 1, D, tmp, mo);
				}
			}
		};

		vector<int> dep;
		dep.resize(n * m);

		function<void(int, int, vector<int> &)> dfs_1 = [&] (int u, int d, vector<int> &Node) {
			dep[u] = d;
			vis[u] = true;
			Node.emplace_back(u);

			for(int v : rev[u]) {
				if(!vis[v]) {
					dfs_1(v, d + 1, Node);
				}
			}
		};

		int ans2 = 0;

		vector<bool> hav;
		hav.resize(n * m);

		for(int i = 0; i < n * m; ++i) {
			if(!vis[i]) {
				vector<int> Node;

				dfs_1(i, 0, Node);

				int m = Node.size();

				vector<int> tmp;

				for(int u : Node) {
					dfs(u, 0, dep[u], tmp, m);
				}

				for(int j : tmp) {
					if(!hav[j]) {
						++ans2;
						hav[j] = true;
					}
				}

				for(int j : tmp) {
					hav[j] = false;
				}
			}
		}

		cout << ans1 << ' ' << ans2 << '\n';
	}

	return 0;
}
