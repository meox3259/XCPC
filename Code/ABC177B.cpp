#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();
	int ans = m;
	for(int p = 0; p + m - 1 < n; ++p) {
		int cnt = 0;
		for(int i = 0; i < m; ++i) {
			cnt += (s[i + p] != t[i]);
		}
		ans = min(ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
