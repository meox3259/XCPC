#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size(), a = 0, b = 0, c = 0, d = 0;
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'L') {
				++a;
			}
			if(s[i] == 'R') {
				++b;
			}
			if(s[i] == 'U') {
				++c;
			}
			if(s[i] == 'D') {
				++d;
			}
		}
		int ans = abs(a - b) + abs(c - d);
		a = min(a, b);
		c = min(c, d);
		if(a == 0 && c == 0) {
			cout << 0 << '\n';
			cout << '\n';
			continue;
		}
		if(a == 0) {
			cout << '2' << '\n';
			cout << "UD" << '\n';
			continue;
		}
		if(c == 0) {
			cout << '2' << '\n';
			cout << "LR" << '\n';
			continue;
		}
		cout << 2 * (a + c) << '\n';
		for(int i = 0; i < a; ++i) {
			cout << 'L';
		}
		for(int i = 0; i < c; ++i) {
			cout << 'D';
		}
		for(int i = 0; i < a; ++i) {
			cout << 'R';
		}
		for(int i = 0; i < c; ++i) {
			cout << 'U';
		}
		cout << '\n';
	}
	return 0;
}
