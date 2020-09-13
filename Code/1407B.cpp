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

		sort(a.begin(), a.end());
		int cur = 0;
		vector<bool> vis(n);
		vector<int> ans;
		for(int i = 0; i < n; ++i) {
			int p = -1;
			int mx = 0;
			for(int j = 0; j < n; ++j) {
				if(!vis[j]) {
					mx = max(mx, __gcd(cur, a[j]));
				}
			}
			for(int j = 0; j < n; ++j) {
				if(!vis[j] && mx == __gcd(cur, a[j])) {
					p = j;
					break;
				}
			}
			vis[p] = true;
			ans.emplace_back(a[p]);
			cur = __gcd(cur, a[p]);
		}

		for(int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}
