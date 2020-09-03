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

		vector<int> w(n);
		for(int i = 0; i < n; ++i) {
			cin >> w[i];
		}

		int ans = 0;
		for(int s = 0; s <= n + n; ++s) {
			vector<int> cnt(n + n + 1);
			for(int i : w) {
				cnt[i] += 1;
			}
			int tmp = 0;
			for(int i = 1; i <= n && i <= s; ++i) {
				if(i + i == s) {
					tmp += cnt[i] / 2;
					cnt[i] %= 2;
				} else {
					int d = min(cnt[i], cnt[s - i]);
					tmp += d;
					cnt[i] -= d;
					cnt[s - i] -= d;
				}
			}
			ans = max(ans, tmp);
		}

		cout << ans << '\n';
	}

	return 0;
}
