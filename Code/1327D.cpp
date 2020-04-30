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

		vector<int> p;
		p.resize(n);

		for(int &i : p) {
			cin >> i;

			--i;
		}

		vector<int> c;
		c.resize(n);

		for(int &i : c) {
			cin >> i;
		}

		vector<bool> vis;
		vis.resize(n);

		int ans = n;

		auto solve = [&] (int u) {
			int ret = n;

			vector<int> cycle;

			while(!vis[u]) {
				cycle.emplace_back(u);
				vis[u] = true;
				u = p[u];
			}

			for(int step = 1; step <= (int)cycle.size(); ++step) {
				if(cycle.size() % step == 0) {
					for(int s = 0; s < step; ++s) {
						bool ok = true;

						for(int pos = s; pos < cycle.size(); pos += step) {
							if(c[cycle[s]] != c[cycle[pos]]) {
								ok = false;
							}			
						}	

						if(ok) {
							ret = min(ret, step);
							break;
						}
					}
				}
			}

			return ret;
		};

		for(int i = 0; i < n; ++i) {
			if(!vis[i]) {
				ans = min(ans, solve(i));
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
