#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	vector<int> v(N + 1);

	int B = (int)sqrt(N);

	vector<vector<long long> > sum(B + 1, vector<long long> (B + 1));

	while (q --) {
		int type;
		cin >> type;

		if (type == 1) {
			int x, y;
			cin >> x >> y;
			v[x] += y;

			for (int i = 1; i <= B; ++i) {
				sum[i][x % i] += y;
			}
		}

		if (type == 2) {
			int x, y;
			cin >> x >> y;

			if (x <= B) {
				cout << sum[x][y] << '\n';
			} else {
				long long ans = 0;
				for (int i = y; i <= N; i += x) {
					ans += v[i];
				}
				cout << ans << '\n';
			}
		}
	}

	return 0;
}
