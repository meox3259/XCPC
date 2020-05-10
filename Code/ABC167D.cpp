#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long long k;
	cin >> n >> k;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	vector<vector<int> > to(n, vector<int> (64, -1));

	for(int i = 0; i < n; ++i) {
		to[i][0] = a[i];
	}

	for(int j = 0; j + 1 < 63; ++j) {
		for(int i = 0; i < n; ++i) {
			to[i][j + 1] = to[to[i][j]][j];
		}
	}

	int cur = 0;

	for(int j = 62; j >= 0; --j) {
		if(k & (1LL << j)) {
			cur = to[cur][j];
		}
	}

	cout << cur + 1 << '\n';

	return 0;
}
