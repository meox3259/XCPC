#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	string ans = "";

	for(int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
	}

	for(int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
	}

	for(int i = 0; i < n - 1; ++i) {
		ans += "U";
	}

	for(int i = 0; i < m - 1; ++i) {
		ans += 'L';
	}

	for(int i = 0; i < n; ++i) {
		if(i & 1) {
			for(int j = 0; j < m - 1; ++j) {
				ans += 'L';
			}
		} else {
			for(int j = 0; j < m - 1; ++j) {
				ans += 'R';
			}
		}
		
		if(i != n - 1) {
			ans += 'D';
		}
	}

	cout << ans.size() << '\n';
	cout << ans << '\n';

	return 0;
}
