#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while(T--) {
		string s;
		cin >> s;

		int n = s.size();

		set<int> S = {0, n + 1};

		for(int i = 0; i < n; ++i) {
			if(s[i] == 'R') {
				S.emplace(i + 1);
			}
		}

		int ans = 0;

		for(auto it = S.begin(); it != S.end(); ++it) {
			if(next(it) != S.end()) {
				ans = max(ans, *next(it) - *it);
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
