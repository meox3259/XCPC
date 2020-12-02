#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int l = -1;
		int r = a[n - 1] + 1;

		auto check = [&] (int d) {
			vector<pair<int, int> > seg;	
			for (int i = 0; i < n; ++i) {
				seg.emplace_back(a[i] - d, -1);
				seg.emplace_back(a[i] + d, 1);
			}

			sort(seg.begin(), seg.end());
			int sum = 0;
			for (auto [p, v] : seg) {
				if (v == -1) {
					sum ++;
				} else {
					sum --;
				}

				if (sum > k) {
					return true;
				}
			} 

			return false;
		};

		while (r - l > 1) {
			int mid = l + r >> 1;
			if (check(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}

		vector<pair<int, int> > seg;
		for (int i = 0; i < n; ++i) {
			seg.emplace_back(a[i] - r, -1);
			seg.emplace_back(a[i] + r, 1);
		}

		sort(seg.begin(), seg.end());
		int sum = 0;
		for (auto [p, v] : seg) {
			if (v == -1) {
				sum += 1;
			} else {
				sum -= 1;
			}

			if (sum > k) {
				cout << p << '\n';
				break;
			}
		}
	}

	return 0;
}
