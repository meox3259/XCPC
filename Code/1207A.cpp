#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int b, p, f;
		cin >> b >> p >> f;

		int h, c;
		cin >> h >> c;

		int ans = 0;
		for (int i = 0; i + i <= b; ++i) {
			int x = min(i, p);
			int y = min((b - i - i) / 2, f);
			ans = max(ans, x * h + y * c);
		}

		cout << ans << '\n';
	}

	return 0;
}
