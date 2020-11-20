#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> l(m);
	vector<int> r(m);
	for(int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i];
	}

	long long ans = 0;
	for(int x = 1; x + k - 1 <= n; ++x) {
		vector<int> s(m);

		auto cross = [&] (int l1, int r1, int l2, int r2) {
			return max(0, min(r1, r2) - max(l1, l2) + 1);
		};

		for(int i = 0; i < m; ++i) {
			s[i] = cross(l[i], r[i], x, x + k - 1);
		}

		vector<long long> d(n + 1);
		for(int i = 0; i < m; ++i) {
			int a = max(cross(1, k, l[i], r[i]), cross(x, x + k - 1, l[i], r[i]));
			int b = max(cross(n - k + 1, n, l[i], r[i]), cross(x, x + k - 1, l[i], r[i]));
			d[0] += a;
			d[1] -= a;
			if(l[i] - k + 1 + a <= n) {
				d[max(0, l[i] - k + 1 + a)] += 1;
			}
			if(r[i] - k + 2 <= n) {
				d[max(0, r[i] - k + 2)] -= 1;
			}
			if(l[i] + 1 <= n) {
				d[l[i] + 1] -= 1;
			}
			if(r[i] + 2 - b <= n) {
				d[max(0, r[i] + 2 - b)] += 1;
			}
		}

		for(int i = 1; i <= n; ++i) {
			d[i] += d[i - 1];
		}

		for(int i = 1; i <= n; ++i) {
			d[i] += d[i - 1];
		}

		ans = max(ans, *max_element(d.begin(), d.end()));
	}

	cout << ans << '\n';

	return 0;
}
