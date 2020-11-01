#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	bool ok = false;
	for(int i = 0; i < n; ++i) {
		map<pair<int, int>, int> mp;
		for(int j = 0; j < n; ++j) {
			if(j != i) {
				int X = x[j] - x[i];
				int Y = y[j] - y[i];
				int d = abs(__gcd(X, Y));
				X /= d;
				Y /= d;
				if(mp.count({-X, -Y})) {
					ok = true;
				}
				mp[{X, Y}] = 1;
			}
		}
	}

	if(ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
