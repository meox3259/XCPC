#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	--x;
	--y;

	vector<int> ans;
	ans.resize(n);

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int d = j - i;

			d = min(d, abs(i - x) + abs(j - y) + 1);

			d = min(d, abs(i - y) + abs(j - x) + 1);

			++ans[d];
		}
	}
	
	for(int i = 1; i < ans.size(); ++i) {
		cout << ans[i] << '\n';
	}

	return 0;
}
