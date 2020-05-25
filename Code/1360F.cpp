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
		string ans = s[0];
		bool ok = false;
		for(int i = 0; i < m; ++i) {
			for(char c = 'a'; c <= 'z'; ++c) {
				ans[i] = c;
				bool same = true;
				for(int j = 0; j < n; ++j) {	
					int cnt = 0;
					for(int k = 0; k < m; ++k) {
						if(ans[k] != s[j][k]) {
							cnt += 1;
						}
					}
					if(cnt > 1) {
						same = false;
					}
				}
				if(same) {
					ok = true;
					break;
				}
			}
			if(ok) {
				break;
			}
			ans[i] = s[0][i];
		}
		if(ok) {
			cout << ans << '\n';
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
