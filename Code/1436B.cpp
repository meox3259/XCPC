#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		int p = -1;

		auto isprime = [&] (int x) -> bool {
			if (x == 1) {
				return false;
			}
			if (x == 2) {
				return true;
			}
			for (int i = 2; i < x; ++i) {
				if (x % i == 0) {
					return false;
				}
			}
			return true;
		};

		for (int i = 1; ; ++i) {
			if (!isprime(i) && isprime(i + n - 1)) {
				p = i;
				break;
			}
		}

		vector<vector<int> > ans(n, vector<int> (n, 1));
		for (int i = 0; i < n; ++i) {
			ans[i][i] = p;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << ans[i][j] << " \n"[j == n - 1];
			}
		}
	}

	return 0;
}
