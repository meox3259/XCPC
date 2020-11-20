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

		map<char, int> mp;
		for(char c : s) {
			mp[c] += 1;
		}

		int mx = 0;
		for(auto it : mp) {
			mx = max(mx, it.second);
		}

		if(mp['R'] == mx) {
			cout << string(s.size(), 'P') << '\n';
		} else if(mp['S'] == mx) {
			cout << string(s.size(), 'R') << '\n';
		} else if(mp['P'] == mx) {
			cout << string(s.size(), 'S') << '\n';
		}
	}

	return 0;
}
