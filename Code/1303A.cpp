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
	int n = s.size(), ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1') {
			int p = -1;
			for(int j = i - 1; ~j; --j) {
				if(s[j] == '1') {
					p = j;
					break;
				}
			}
			if(p != -1) {
				ans += i - p - 1;
			}
		}
	}
	cout << ans << '\n';
	}
	return 0;
}
