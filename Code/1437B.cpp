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

		string s;
		cin >> s;

		int ans = 0;
		for(int i = 0; i + 1 < s.size(); ++i) {
			ans += (s[i] == s[i + 1]);
		}

		cout << (ans + 1) / 2 << '\n';
	}

	return 0;
}
