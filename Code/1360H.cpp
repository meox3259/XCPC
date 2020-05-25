#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		sort(s.begin(), s.end());
		string ans(m, '0');
		long long cur = ((1LL << m) - n - 1) / 2;
		for(int i = m - 1; i >= 0; --i) {
			if(cur >= (1LL << i)) {
				ans[m - i - 1] = '1';
				cur -= 1LL << i;
			}
		}
		for(int i = 0; i < n; ++i) {
			if(ans >= s[i]) {
				for(int j = m - 1; j >= 0; --j) {
					if(ans[j] == '0') {
						ans[j] = '1';
						break;
					} else {
						ans[j] = '0';
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
