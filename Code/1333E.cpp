#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if(n < 3) {
		cout << -1 << '\n';
		return 0;
	}

	vector<vector<int> > ans;
	ans.resize(n);
	for(int i = 0; i < n; ++i) {
		ans[i].resize(n);
	}

	ans[0][0] = 1; ans[0][1] = 7; ans[0][2] = 9;
	ans[1][0] = 3; ans[1][1] = 2; ans[1][2] = 5;
	ans[2][0] = 4; ans[2][1] = 8; ans[2][2] = 6;

	int cur = 0;

	for(int i = n - 1; i > 2; --i) {
		if(i & 1) {
			for(int j = 0; j <= i; ++j) {
				ans[j][i] = ++cur;
			}

			for(int j = i - 1; j >= 0; --j) {
				ans[i][j] = ++cur;
			}
		} else {
			for(int j = 0; j <= i; ++j) {
				ans[i][j] = ++cur;
			}

			for(int j = i - 1; j >= 0; --j) {
				ans[j][i] = ++cur;
			}
		}
	}

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			ans[i][j] += cur;
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << ans[i][j] << " \n"[j == n - 1];
		}
	}

	return 0;
}
