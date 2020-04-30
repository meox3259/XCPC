#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int h, g;
		cin >> h >> g;

		int n = (1 << h) - 1;
		int m = (1 << g) - 1;

		vector<int> a(n * 2 + 5);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
		}

		long long sum = 0;
		for(int i = 1; i <= n; ++i) {
			sum += a[i];
		}

		auto leaf = [&] (int x) -> int {
			while(a[x << 1] != 0 || a[x << 1 | 1] != 0) {
				if(a[x << 1] > a[x << 1 | 1]) {
					x = x << 1;
				} else {
					x = x << 1 | 1;
				}
			}
			return x;
		};

		function<void(int)> del = [&] (int x) {
			if(a[x << 1] == 0 && a[x << 1 | 1] == 0) {
				a[x] = 0;
				return;
			}
			if(a[x << 1] < a[x << 1 | 1]) {
				a[x] = a[x << 1 | 1];
				del(x << 1 | 1);
			} else {
				a[x] = a[x << 1];
				del(x << 1);
			}
		};

		vector<int> ans;

		for(int i = 1; i <= m; ++i) {
			while(leaf(i) > m) {
				ans.emplace_back(i);
				sum -= a[i];
				del(i);
			}
		}

		cout << sum << '\n';
		for(int i : ans) {
			cout << i << " ";
		}
		cout << '\n';
	}

	return 0;
}
