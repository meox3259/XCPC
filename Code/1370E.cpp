#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int cnts = 0;
	int cntt = 0;

	for(char c : s) {
		cnts += (c == '0');
	}
	for(char c : t) {
		cntt += (c == '0');
	}

	if(cnts != cntt) {
		cout << -1 << '\n';
		exit(0);
	}

	int cnt0 = 0;
	int cnt1 = 0;

	for(int i = 0; i < n; ++i) {
		if(s[i] == '0' && t[i] == '1') {
			if(cnt1 > 0) {
				cnt1 -= 1;
				cnt0 += 1;
			} else {
				cnt0 += 1;
			}
		}
		if(s[i] == '1' && t[i] == '0') {
			if(cnt0 > 0) {
				cnt0 -= 1;
				cnt1 += 1;
			} else {
				cnt1 += 1;
			}
		}
	}

	cout << cnt0 + cnt1 << '\n';

	return 0;
}
