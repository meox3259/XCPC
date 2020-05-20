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
		vector<vector<int> > near(n, vector<int> (3, -1));
		near[0][s[0] - '0' - 1] = 0;
		for(int i = 0; i + 1 < n; ++i) {
			for(int j = 0; j < 3; ++j) {
				near[i + 1][j] = near[i][j];
			}
			near[i + 1][s[i + 1] - '0' - 1] = i + 1;
		}
		bool ok = true;
		for(int i = 0; i < 3; ++i) {
			if(near[n - 1][i] == -1) {
				ok = false;
			}
		}
		if(!ok) {
			cout << 0 << '\n';
		} else {
			int ans = n;
			for(int i = 0; i < n; ++i) {
				int left = n;
				for(int j = 0; j < 3; ++j) {
					left = min(left, near[i][j]);
				}
				if(left != -1) {
					ans = min(ans, i - left + 1);
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
