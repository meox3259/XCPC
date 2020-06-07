#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<bool> r(n);
		vector<bool> c(m);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				if(x == 1) {
					r[i] = true;
					c[j] = true;
				}
			}
		}
		int x = 0;
		int y = 0;
		for(int i = 0; i < n; ++i) {
			if(!r[i]) {
				x += 1;
			}
		}
		for(int i = 0; i < m; ++i) {
			if(!c[i]) {
				y += 1;
			}
		}
		int z = min(x, y);
		if(z % 2 == 0) {
			cout << "Vivek" << '\n';
		} else {
			cout << "Ashish" << '\n';
		}
	}

	return 0;
}
