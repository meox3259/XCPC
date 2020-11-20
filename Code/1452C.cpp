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

		int x = 0;
		int y = 0;
		int ans = 0;
		for(char c : s) {
			if(c == '(') {
				x += 1;
			}
			if(c == ')') {
				if(x > 0) {
					x -= 1;
					ans += 1;
				}
			}
			if(c == '[') {
				y += 1;
			}
			if(c == ']') {
				if(y > 0) {
					y -= 1;
					ans += 1;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
