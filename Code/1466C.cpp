#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max() / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		string s;
		cin >> s;

		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if ((i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2])) {
				ans ++;
				s[i] = '?';
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
