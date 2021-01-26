#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		vector<vector<int> > v(2);
		for (int i = 0; i < n; ++i)	{
			v[b[i] - 1].emplace_back(a[i]);
		}

		for (int i = 0; i < 2; ++i) {
			sort(v[i].begin(), v[i].end(), greater<int> ());
		}

		long long sum = 0;
		for (int i : v[1]) {
			sum += i;
		}

		int ans = inf;
		int j = (int)v[1].size() - 1;
		while (j >= 0 && sum - v[1][j] >= m) {
			sum -= v[1][j];
			j --;
		}
		if (sum >= m) {
			ans = min(ans, (j + 1) * 2);
		}
		for (int i = 0; i < v[0].size(); ++i) {
			sum += v[0][i];
			while (j >= 0 && sum - v[1][j] >= m) {
				sum -= v[1][j];
				j --;
			}	
			if (sum >= m) {
				ans = min(ans, i + 1 + (j + 1) * 2);
			}
		}

		if (ans == inf) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}

	return 0;
}
