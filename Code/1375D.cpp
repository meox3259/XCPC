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

		auto mex = [&] (const vector<int> &a) {
			vector<bool> vis(1005);
			int cur = 0;
			for(int i : a) {
				vis[i] = true;
			}
			while(vis[cur]) {
				cur += 1;
			}
			return cur;
		};

		auto check = [&] (const vector<int> &a) {
			for(int i = 0; i + 1 < a.size(); ++i) {
				if(a[i] > a[i + 1]) {
					return false;
				}
			}
			return true;
		};

		int cur = 0;
		vector<int> ans;
		while(!check(a)) {
			int v = mex(a);
			if(v == n) {
				for(int i = 0; i < n; ++i) {
					if(a[i] != i) {
						ans.emplace_back(i);
						a[i] = n;
						break;
					}
				}
			} else {
				ans.emplace_back(v);
				a[v] = v;
			}
		}

		cout << ans.size() << '\n';
		for(int i : ans) {
			cout << i + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
