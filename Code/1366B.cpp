#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x, m;
		cin >> n >> x >> m;
		int low = x;
		int up = x;
		for(int i = 0; i < m; ++i) {
			int l, r;
			cin >> l >> r;
			if(!(up < l || low > r)) {
				low = min(low, l);
				up = max(up, r);
			}
		}
		cout << up - low + 1 << '\n';
	}

	return 0;
}
