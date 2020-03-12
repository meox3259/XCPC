#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	while(q--) {
		int c, m, x;
		cin >> c >> m >> x;
		if(c > m) {
			swap(c, m);
		}
		cout << min(c, (c + m + x) / 3) << '\n';
	}
	/*
	 	0 < t <= c
		c + m + x - 2 * t
	 */
	return 0;
}
