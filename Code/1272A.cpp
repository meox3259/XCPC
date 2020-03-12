#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	while(T--) {
		long long a, b, c, ans = 1e18;
		cin >> a >> b >> c;
		for(int x = -1; x <= 1; ++x) {
			for(int y = -1; y <= 1; ++y) {
				for(int z = -1; z <= 1; ++z) {
					ans = min(ans, abs(a + x - b - y) + abs(a + x - c - z) + abs(b + y - c - z));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
