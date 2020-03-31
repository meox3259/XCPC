#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;

	vector<vector<int> > ans;
	ans.resize(3);

	for(int i = 0; i < 3; ++i) {
		ans[i].resize(3);
	}

	int x = 1 << 17;

	ans[0][0] = k + x; ans[0][1] = x; ans[0][2] = 0;
	ans[1][0] = k; ans[1][1] = k + x; ans[1][2] = k;
	ans[2][2] = k;

	cout << 3 << ' ' << 3 << '\n';

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			cout << ans[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
