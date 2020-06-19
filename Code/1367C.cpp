#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		set<int> pos = { -inf, inf };
	
		for(int i = 0; i < n; ++i) {
			if(s[i] == '1') {
				pos.emplace(i);
			}
		}

		int ans = 0;

		for(int i = 0; i < n; ++i) {
			if(s[i] == '0') {
				auto it = pos.lower_bound(i);
				if(*it - i > k && i - *prev(it) > k) {
					ans += 1;
					pos.emplace(i);
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
