#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a;
	a.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> delta;
	delta.resize(2 * m + 1);

	long long sum = 0;

	for(int i = 0; i < n - 1; ++i) {
		if(a[i] < a[i + 1]) {
			sum += a[i + 1] - a[i];
		} else {
			sum += a[i + 1] + m - a[i];
		}
	}

	vector<long long> add;
	add.resize(2 * m);

	for(int i = 0; i < n - 1; ++i) {
		int x = a[i] - 1;
		int y = a[i + 1] - 1;
		
		if(x < y) {
			++delta[x];
			--delta[y];
			add[y] += y - x;
		} else {
			++delta[x];
			--delta[y + m];
			add[y + m] += y + m - x;
		}
	}

	long long tot = 0;
	long long d = 0;

	vector<long long> ans;
	ans.assign(m, sum);

	for(int i = 0; i < 2 * m; ++i) {
		tot += d;
		ans[i % m] -= tot - d;
		tot -= add[i];
		d += delta[i];
	}

	cout << *min_element(ans.begin(), ans.end()) << '\n';

	return 0;
}
