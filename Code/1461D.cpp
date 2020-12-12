#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, q;
		cin >> n >> q;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		sort(a.begin(), a.end());
		vector<long long> pre(n + 1);
		for (int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + a[i];
		}

		map<long long, int> mp;

		function<void(int, int, long long)> dfs = [&] (int l, int r, long long sum) {
			mp[sum] = 1;
			if (a[l] == a[r]) {
				return;
			}
			long long mid = (a[l] + a[r]) / 2;
			int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
			dfs(l, p - 1, pre[p] - pre[l]);
			dfs(p, r, pre[r + 1] - pre[p]);
		};

		dfs(0, n - 1, pre[n]);

		while (q --) {
			int s;
			cin >> s;

			if (mp[s]) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
	}

	return 0;
}
