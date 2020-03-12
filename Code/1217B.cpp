#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, x;
		cin >> n >> x;
		int mn = inf;
		int mx = 0;
		for(int i = 0; i < n; ++i) {
			int d, h;	
			cin >> d >> h;
			mx = max(mx, d);
			mn = min(mn, h - d);
		}
		if(x <= mx) {
			cout << 1 << '\n';
		} else {
			if(mn >= 0) {
				cout << -1 << '\n';
			} else {
				mn = -mn;
				cout << (x - mx + mn - 1) / mn + 1 << '\n';
			}
		}
	}
	return 0;
}
