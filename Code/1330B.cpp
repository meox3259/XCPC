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

		vector<int> a;
		a.resize(n);

		for(int &i : a) {
			cin >> i;
		}

		vector<bool> pre;
		pre.resize(n);

		vector<bool> suf;
		suf.resize(n);

		vector<pair<int, int> > ans;

		function<void(vector<bool> &)> solve = [&] (vector<bool> &pre) {
			int mx = 0;

			vector<bool> vis;
			vis.resize(n);

			bool ok = true;

			for(int i = 0; i < n; ++i) {
				mx = max(mx, a[i]);

				if(vis[a[i]]) {
					ok = false;
				} else {
					vis[a[i]] = true;
				}

				if(mx == i + 1 && ok) {
					pre[i] = true;
				}
			}
		};

		solve(pre);

		reverse(a.begin(), a.end());

		solve(suf);

		reverse(suf.begin(), suf.end());

		for(int i = 0; i + 1 < n; ++i) {
			if(pre[i] && suf[i + 1]) {
				ans.emplace_back(i + 1, n - i - 1);
			}		
		}

		cout << ans.size() << '\n';

		for(auto [u, v] : ans) {
			cout << u << ' ' << v << '\n';
		}
	}

	return 0;
}
