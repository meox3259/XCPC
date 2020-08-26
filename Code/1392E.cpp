#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<long long> > a(n + 1, vector<long long> (n + 1));			

	long long big = 1LL << (n + n);
	for(int i = 1; i < n; i += 2) {
		long long cur = big;
		for(int j = 0; j < n; ++j) {
			a[i][j] = cur;
			cur /= 2;
		}
		big /= 4;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	fflush(stdout);

	int q;
	cin >> q;

	while(q--) {
		long long k;
		cin >> k;
		vector<pair<int, int> > ans;
		int x = 0;
		int y = 0;
		ans.emplace_back(0, 0);
		for(int i = 0; i < 2 * n - 2; ++i) {
			if(x % 2 == 0) {
				if(k & a[x + 1][y]) {
					x += 1;
				} else {
					y += 1;
				}
			} else {
				if(k & a[x][y + 1]) {
					y += 1;
				} else {
					x += 1;
				}
			}
			ans.emplace_back(x, y);
		}

		for(auto [x, y] : ans) {
			cout << x + 1 << ' ' << y + 1 << '\n'; 
		}

		fflush(stdout);
	}

	return 0;
}
