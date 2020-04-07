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
		bool ok = true;
		for(int i = 0; i + 1 < n; ++i) {
			if(s[i] == s[i + 1] && s[i] != '?') {
				ok = false;
			}
		}
		if(!ok) {
			cout << -1 << '\n';
			continue;
		}
		for(int i = 0; i < n; ++i) {
			if(s[i] == '?') {
				for(char c = 'a'; c < 'd'; ++c) {
					if((i == 0 || c != s[i - 1]) && (i + 1 == n || c != s[i + 1])) {
						cout << (s[i] = c);
						break;
					}
				}
			} else {
				cout << s[i];
			}
		}
		cout << '\n';
	}
	return 0;
}
