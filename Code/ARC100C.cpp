#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int m = 1 << n;

	vector<int> a;
	a.resize(m);

	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	vector<int> dp_1;
	dp_1.resize(m);
	iota(dp_1.begin(), dp_1.end(), 0);

	vector<int> dp_2;
	dp_2.assign(m, -1);

	for(int S = 0; S < m; ++S) {
		for(int i = 0; i < n; ++i) {
			if((S >> i & 1) == 0) {
				if(dp_1[S] != dp_1[S ^ (1 << i)]) {
					if(a[dp_1[S]] >= a[dp_1[S ^ (1 << i)]]) {
						dp_2[S ^ (1 << i)] = dp_1[S ^ (1 << i)];
						dp_1[S ^ (1 << i)] = dp_1[S];
					} else if(dp_2[S ^ (1 << i)] == -1 || a[dp_1[S]] > a[dp_2[S ^ (1 << i)]]) {
						dp_2[S ^ (1 << i)] = dp_1[S];
					}
				}
			}
		}
	}

	int ans = -inf;

	for(int i = 1; i < m; ++i) {
		ans = max(ans, a[dp_1[i]] + a[dp_2[i]]);
		cout << ans << '\n';
	}

	return 0;
}
