#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, t;
	cin >> s >> t;

	int ans = 0;
	for(int i = 0; i < s.size(); ++i) {
		ans += (s[i] != t[i]);
	}

	cout << ans << '\n';

	return 0;
}
