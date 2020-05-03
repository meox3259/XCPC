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
		set<int> s;
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			s.emplace(x);
		}

		if(s.size() > k) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> ans;
		for(int i : s) {
			ans.emplace_back(i);
		}
		int m = ans.size();
		for(int i = 0; i < k - m; ++i) {
			ans.emplace_back(1);
		}
		cout << k * n << '\n';
		for(int i = 0; i < n; ++i) {
			for(int j : ans) {
				cout << j << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
