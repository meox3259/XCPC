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

		vector<int> pos(n);

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			--x;
			pos[x] = i;
		}

		vector<bool> vis(n);
	
		long long ans = 0;

		vector<int> b(m);
		for(int i = 0; i < m; ++i) {
			cin >> b[i];
			--b[i];
		}

		vector<int> c(b);
		sort(c.begin(), c.end(), [&] (int i, int j) {
			return pos[i] > pos[j];
		});

		int cnt = 0;
		for(int i = 0; i < m; ++i) {
			if(vis[b[i]]) {
				++cnt;
				++ans;
				continue;
			}
			int d = 0;
			while(!c.empty() && pos[c.back()] <= pos[b[i]]) {
				vis[c.back()] = true;
				c.pop_back();
			}
			ans += (pos[b[i]] - cnt) * 2 + 1;
			cnt += 1;
		}

		cout << ans << '\n';
	}

	return 0;
}
