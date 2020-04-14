#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, x;
		cin >> n >> x;

		vector<bool> vis;
		vis.resize(1005);

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			vis[x] = true;
		}

		int sum = 0;
		int ans = 0;

		for(int i = 1; i <= n + x; ++i) {
			if(vis[i]) {
				++sum;
			}

			if(sum + x >= i) {
				ans = i;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
