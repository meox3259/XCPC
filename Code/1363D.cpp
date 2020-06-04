#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<bool> vis(n + 1);
		vector<vector<int> > index(k + 1);
		for(int i = 0; i < k; ++i) {
			int c;
			cin >> c;
			for(int j = 0; j < c; ++j) {
				int p;
				cin >> p;
				--p;
				index[i].emplace_back(p);
				vis[p] = true;
			}
		}
		for(int i = 0; i < n; ++i) {
			if(!vis[i]) {
				index[k].emplace_back(i);
			}
		}

		auto query = [&] (int l, int r) {
			int ret = 0;
			vector<int> ask;
			for(int i = l; i <= r; ++i) {
				for(int j : index[i]) {
					ask.emplace_back(j);
				}
			}
			cout << '?';
			cout << ' ' << ask.size();
			for(int i : ask) {
				cout << ' ' << i + 1;
			}
			cout << endl;
			cin >> ret;
			return ret;
		};

		int l = 0;
		int r = k;
		int cur = query(0, k);

		while(l != r) {
			int mid = l + r >> 1;
			if(query(l, mid) == cur) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		vector<int> ans(k);
		for(int i = 0; i < k; ++i) {
			if(i != l) {
				ans[i] = cur;
			}
		}
		if(l != k) {
			vector<int> ask;
			for(int i = 0; i <= k; ++i) {
				if(i != l) {
					for(int j : index[i]) {
						ask.emplace_back(j);
					}
				}
			}
			cout << '?' << ' ' << ask.size();
			for(int i : ask) {
				cout << ' ' << i + 1;
			}
			cout << endl;
			cin >> ans[l];
		}
		cout << '!';
		for(int i : ans) {
			cout << ' ' << i;
		}
		cout << endl;
		string verdict;
		cin >> verdict;
	}

	return 0;
}
