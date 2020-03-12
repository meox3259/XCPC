#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	a.resize(n);
	b.resize(n);
	for(int i = 0; i < n; ++i) {
		int A;
		cin >> A;
		while(A--) {
			int x, y;
			cin >> x >> y;
			--x;
			if(y == 0) {
				b[i] |= 1 << x;
			} else {
				a[i] |= 1 << x;
			}
		}
	}
	int ans = 0;
	for(int S = 0; S < 1 << n; ++S) {
		bool f = true;
		for(int i = 0; i < n; ++i) {
			if(S >> i & 1) {
				if(((S & a[i]) != a[i]) || ((S & b[i]) != 0)) {
					f = false;
				}
			}
		}
		if(f == true) {
			ans = max(ans, __builtin_popcount(S));
		}
	}
	cout << ans << '\n';
	return 0;
}
