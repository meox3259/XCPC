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

		map<int, int> cnt;

		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;

			++cnt[x];
		}

		int m = cnt.size();
		int ans = 0;

		for(auto p : cnt) {
			ans = max(ans, min(m - 1, p.second));
			ans = max(ans, min(m, p.second - 1));
		}

		cout << ans << '\n';
	}

	return 0;
}
