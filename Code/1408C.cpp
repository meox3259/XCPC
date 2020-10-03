#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, L;
		cin >> n >> L;

		vector<int> a;
		a.emplace_back(0);
		for(int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			a.emplace_back(tmp);
		}

		a.emplace_back(L);
		n = a.size();

		double l = 0.0;
		double r = L;

		auto check = [&] (double t) {
			double cur = 1.;
			double rem = t;
			double l = 0.;
			for(int i = 0; i + 1 < n; ++i) {
				double tmp = (a[i + 1] - a[i]) / cur;
				l += min(tmp, rem) * cur;
				cur += 1.;
				rem -= min(tmp, rem);
			}
			cur = 1.;
			rem = t;
			double r = 0.;
			for(int i = n - 1; i >= 1; --i) {
				double tmp = (a[i] - a[i - 1]) / cur;
				r += min(tmp, rem) * cur;
				cur += 1.;
				rem -= min(tmp, rem);
			}
			return l + r >= L;
		};

		for(int _ = 0; _ < 100; ++_) {
			double mid = (l + r) / 2.;
			if(check(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		cout << fixed << setprecision(10);
		cout << r << '\n';
	}

	return 0;
}
