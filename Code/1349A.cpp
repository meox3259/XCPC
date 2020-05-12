#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int> > v(200001);
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		for(int j = 2; j * j <= x; ++j) {
			if(x % j == 0) {
				int c = 1;
				while(x % j == 0) {
					x = x / j;
					c = c * j;
				}
				v[j].emplace_back(c);
			}
		}

		if(x > 1) {
			v[x].emplace_back(x);
		}
	}

	long long ans = 1;

	for(int i = 2; i <= 200000; ++i) {
		sort(v[i].begin(), v[i].end());
		if(v[i].size() == n) {
			ans = ans * v[i][1];
		} else if(v[i].size() == n - 1) {
			ans = ans * v[i][0];
		}
	}

	cout << ans << '\n';

	return 0;
}
