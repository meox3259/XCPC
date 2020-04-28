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

		vector<bool> vis;
		vis.resize(n);

		vector<bool> match;
		match.resize(n);

		for(int i = 0; i < n; ++i) {
			int k;
			cin >> k;

			vector<int> g;
			g.resize(k);

			for(int &j : g) {
				cin >> j;
				--j;
			}

			for(int j : g) {
				if(!vis[j]) {
					vis[j] = true;
					match[i] = true;
					break;
				}
			}
		}

		int x = -1;
		int y = -1;

		for(int i = 0; i < n; ++i) {
			if(!match[i]) {
				x = i;
			}
		}

		for(int i = 0; i < n; ++i) {
			if(!vis[i]) {
				y = i;
			}
		}

		if(x == -1) {
			cout << "OPTIMAL" << '\n';
		} else {
			cout << "IMPROVE" << '\n';
			cout << x + 1 << ' ' << y + 1 << '\n';
		}
	}

	return 0;
}
