#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, x;
		cin >> n >> x;
		string s;
		cin >> s;
		vector<int> pre(n + 5, 0);
		for(int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + (s[i] == '1' ? -1 : 1);
		}
		int tmp = pre[n], ans = 0;
		bool f = 1;
		if(tmp == 0) {
			for(int i = 1; i <= n; ++i) {
				if(pre[i] == x) {
					f = 0;
					break;
				}
			}
			if(!f) {
				cout << -1 << '\n';
				continue;
			}
			if(x == 0) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
			continue;
		}
		if(x == 0) {
			++ans;
		}
		for(int i = 1; i <= n; ++i) {
			if(abs(x - pre[i]) % abs(tmp) == 0) {
				if((x < pre[i] && tmp < 0) || (x > pre[i] && tmp > 0) || (x == pre[i])) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
