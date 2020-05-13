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

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<bool> vis(n + 1);

		for(int i = 0; i < n; ++i) {
			int sum = a[i];
			for(int j = i + 1; j < n; ++j) {
				sum += a[j];
				if(sum <= n) {
					vis[sum] = true;
				}
			}
		}

		int ans = 0;

		for(int i = 0; i < n; ++i) {
			if(vis[a[i]]) {
				++ans;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
