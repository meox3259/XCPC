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

		string s;
		cin >> s;

		vector<int> cnt(26);

		for(char c : s) {
			cnt[c - 'a'] += 1;
		}

		int ans = 0;

		for(int i = 1; i <= n; ++i) {
			if(k % i == 0) {
				ans = max(ans, i);
			} else {
				int x = __gcd(i, k % i);
				int y = __gcd(i, i - k % i);
				if(x != 0 && i % x == 0) {
					int t = i / x;
					int tot = 0;
					for(int j = 0; j < 26; ++j) {
						tot += cnt[j] / t;
					}
					if(tot >= x) {
						ans = max(ans, i);
					}
				}
				if(y != 0 && i % y == 0) {
					int t = i / y;
					int tot = 0;
					for(int j = 0; j < 26; ++j) {
						tot += cnt[j] / t;
					}
					if(tot >= y) {
						ans = max(ans, i);
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
