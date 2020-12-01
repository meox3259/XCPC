#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		string s, t, p;
		cin >> s >> t >> p;

		vector<int> cnt(26);
		for (char c : p) {
			cnt[c - 'a'] ++;
		}

		bool ok = true;
		int j = 0;
		for (int i = 0; i < t.size(); ++i) {
			if (j < s.size() && t[i] == s[j]) {
				j += 1;
			} else {
				if (cnt[t[i] - 'a'] > 0) {
					cnt[t[i] - 'a'] --;
				} else {
					ok = false;
					break;
				}
			}
		}

		if (j < s.size()) {
			ok = false;
		}

		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
