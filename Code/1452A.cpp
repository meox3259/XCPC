#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int x, y;
		cin >> x >> y;

		if(x > y) {
			swap(x, y);
		}

		int ans = 0;
		ans += x + x;
		y -= x;
		if(y > 0) {
			ans += y;
			ans += y - 1;
		}
		cout << ans << '\n';
	}

	return 0;
}
