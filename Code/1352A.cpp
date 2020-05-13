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

		int ans = 0;
		for(char c : s) {
			if(c != '0') {
				++ans;
			}
		}

		cout << ans << '\n';

		for(int i = 0; i < n; ++i) {
			if(s[i] != '0') {
				cout << s[i];
				for(int j = i + 1; j < n; ++j) {
					cout << '0';
				}
				cout << ' ';
			}
		}

		cout << '\n';
	}

	return 0;
}
