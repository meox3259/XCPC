#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		int n = s.size();
		
		vector<int> p;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') {
				p.emplace_back(i);
			}
		}

		for (int i : p) {
			s[i] = ')';
		}

		auto check = [&] (string s) {
			int sum = 0;
			bool ok = true;
			for (char c : s) {
				if (c == '(') {
					sum ++;
				} else {
					sum --;
				}
				if (sum < 0) {
					ok = false;
				}
			}

			if (sum != 0) {
				ok = false;
			}

			return ok;
		};

		bool ok = check(s);

		for (int x : p) {
			s[x] = '(';
			if (check(s)) {
				ok = true;
			}
		}

		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
