#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, x, y;
		cin >> n >> x >> y;
		int t = x + y;
		int mx;
		int mn;
		if(x + y <= n) {
			mn = 1;
			mx = x + y - 1;
		} else {
			mx = n;
			int t = x + y - n + 1;
			mn = min(t, n);
		}
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}
