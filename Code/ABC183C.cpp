#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int> > t(n, vector<int> (n));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> t[i][j];
		}
	}

	vector<int> id(n);
	iota(id.begin(), id.end(), 0);

	int ans = 0;

	do {
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			sum += t[id[i]][id[(i + 1) % n]];
		}
		if(sum == k) {
			ans += 1;
		}
	} while(next_permutation(id.begin(), id.end()));

	cout << ans / n << '\n';

	return 0;
}
