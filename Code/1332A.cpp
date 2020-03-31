#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;

		long long x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		x -= a - b;
		y -= c - d;

		if(x1 <= x && x <= x2 && y1 <= y && y <= y2 && (x1 != x2 || (a == 0 && b == 0)) && (y1 != y2 || (c == 0 && d == 0))) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
