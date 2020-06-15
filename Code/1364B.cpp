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

		vector<int> p(n);
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		
		vector<int> ans;
		for(int i = 0; i < n; ++i) {
			if(i == 0 || i == n - 1 || ((p[i - 1] < p[i]) != (p[i] < p[i + 1]))) {
				ans.emplace_back(p[i]);
			}
		}

		cout << ans.size() << '\n';
		for(int i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}
