#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int w, h, n;
		cin >> w >> h >> n;

		long long x = 1;
		long long y = 1;

		while (w % 2 == 0) {
			w /= 2;
			x = x * 2;
		}

		while (h % 2 == 0) {
			h /= 2;
			y = y * 2;
		}

		if (x * y < n) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}
