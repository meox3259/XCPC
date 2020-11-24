#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, q;
		cin >> n >> q;

		string s;
		cin >> s;

		while(q--) {
			int l, r;
			cin >> l >> r;
			--l; --r;

			bool ok = false;
			for(int i = r + 1; i < n; ++i) {
				if(s[i] == s[r]) {
					ok = true;
				}
			}

			for(int i = 0; i < l; ++i) {
				if(s[l] == s[i]) {
					ok = true;
				}
			}

			if(ok) {
				cout << "YES" << '\n';
			} else {
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}
