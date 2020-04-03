#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x;
	x.resize(n);

	vector<int> y;
	y.resize(n);

	vector<pair<long double, int> > p;
	p.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		p[i] = {atan2(y[i], x[i]), i};
	}

	sort(p.begin(), p.end());

	long double ans = 0;

	for(int i = 0; i < n; ++i) {
		long double sx = 0;
		long double sy = 0;
		for(int j = i; j < n + i; ++j) {
			sx += x[p[j % n].second];
			sy += y[p[j % n].second];
			ans = max(ans, sqrt(sx * sx + sy * sy));
		}
	}

	cout << fixed << setprecision(10);

	cout << ans << '\n';

	return 0;
}
