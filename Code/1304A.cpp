#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		long long a, b, x, y;
		cin >> x >> y >> a >> b;
		if((y - x) % (a + b) != 0) {
			cout << -1 << '\n';
		} else {
			cout << (y - x) / (a + b) << '\n';
		}
	}
	return 0;
}
