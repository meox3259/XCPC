#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		vector<int> x(n);
		vector<int> y(n);
		vector<vector<int> > G(n);
		for (int i = 0; i < m; ++i) {
			cin >> x[i] >> y[i];
			x[i] --;
			y[i] --;
			if (x[i] == y[i]) {
				continue;
			}
			G[x[i]].emplace_back(y[i]);
			G[y[i]].emplace_back(x[i]);
		}

		int ans = 0;	
		vector<bool> vis(n);
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				queue<int> q;
				q.emplace(i);
				vis[i] = true;
				int e = 0;
				int c = 0;
				while (!q.empty()) {
					int x = q.front();
					q.pop();
					c ++;
					for (int y : G[x]) {
						e ++;	
						if (!vis[y]) {
							vis[y] = true;
							q.emplace(y);
						}
					}
				}

				e /= 2;
				if (e == c - 1) {
					ans += e;
				} else {
					ans += e + 1;
				}
			}
		}
		
		cout << ans << '\n';
	}

	return 0;
}
