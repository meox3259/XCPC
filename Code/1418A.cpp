#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long x, y, k;
		cin >> x >> y >> k;
		long long t = x - 1;
		long long ans = 0;
		ans += (k * y + t - 2 + k) / t + k;
		cout << ans << '\n';
	}

	return 0;
}
