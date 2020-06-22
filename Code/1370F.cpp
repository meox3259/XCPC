#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<vector<int> > G(n);
		vector<int> d(n);

		for(int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			G[u].emplace_back(v);
			G[v].emplace_back(u);
			d[u] += 1;
			d[v] += 1;
		}

		vector<int> q;

		for(int i = 0; i < n; ++i) {
			if(d[i] == 1) {
				q.emplace_back(i);
			}
		}

		vector<int> node;

		for(int i = 0; i < n; ++i) {
			node.emplace_back(i);
		}

		auto query = [&] (vector<int> querys) {
			cout << '?' << ' ' << querys.size();
			for(int i : querys) {
				cout << ' ' << i + 1;
			}
			cout << endl;
			int x, d;
			cin >> x >> d;
			--x;
			return make_pair(x, d);
		};

		auto [root, mind] = query(node);

		vector<int> dep(n);
		function<void(int, int)> dfs = [&] (int u, int f) {
			for(int v : G[u]) {
				if(v != f) {
					dep[v] = dep[u] + 1;
					dfs(v, u);
				}
			}
		};

		dfs(root, -1);

		int u = -1;
		int v = -1;

		auto check = [&] (int d) {
			vector<int> node;
			for(int i = 0; i < n; ++i) {
				if(dep[i] == d) {
					node.emplace_back(i);
				}
			}
			auto [x, dis] = query(node);
			if(dis == mind) {
				u = x;
				return true;
			}
			return false;
		};

		int l = mind / 2 - 1;
		int r = min(mind, *max_element(dep.begin(), dep.end())) + 1;
		while(r - l > 1) {
			int mid = l + r >> 1;
			if(check(mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}

		vector<int> tmp;

		function<void(int, int, int)> dfs_1 = [&] (int u, int f, int d) {
			if(d == mind) {
				tmp.emplace_back(u);
			}
			for(int v : G[u]) {
				if(v != f) {
					dfs_1(v, u, d + 1);
				}
			}	
		};

		dfs_1(u, -1, 0);

		auto [x, y] = query(tmp);
		v = x;

		cout << '!' << ' ' << u + 1 << ' ' << v + 1 << endl;
		
		string status;
		cin >> status;
	}

	return 0;
}
