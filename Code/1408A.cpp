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

		vector<vector<int> > a(n, vector<int> (3));
		for(int j = 0; j < 3; ++j) {
			for(int i = 0; i < n; ++i) {
				cin >> a[i][j];
			}
		}

		auto dec = [&] (int x) {
			return (x - 1 + n) % n;
		};

		auto inc = [&] (int x) {
			return (x + 1) % n;
		};

		vector<int> ans(n, -1);
		for(int i = 0; i < n; ++i) {
			for(int x = 0; x < 3; ++x) {
				if(a[i][x] != ans[dec(i)] && a[i][x] != ans[inc(i)]) {
					ans[i] = a[i][x];
					break;
				}
			}
		}

		for(int i = 0; i < n; ++i) {
			cout << ans[i] << " \n"[i == n - 1];
		}
	}


	return 0;
}
