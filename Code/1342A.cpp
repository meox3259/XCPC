#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;

		if(a * 2 <= b) {
			cout << (x + y) * a << '\n';
		} else {
			long long ans = 0;
			long long t = min(x, y);
			ans += t * b;
			ans += (x + y - 2 * t) * a;
			cout << ans << '\n';
		}
	}

	return 0;
}
