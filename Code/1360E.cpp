#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;
		vector<string> s(n);
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		bool f = true;
		vector<vector<bool> > ok(n, vector<bool> (n, false));
		for(int i = n - 1; i >= 0; --i) {
			for(int j = n - 1; j >= 0; --j) {
				if(s[i][j] == '1') {
					if(i == n - 1 || j == n - 1) {
						ok[i][j] = true;
					} else if(ok[i + 1][j] || ok[i][j + 1]) {
						ok[i][j] = true;
					} else {
						f = false;
					}
				}
			}
		}
		if(f) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
