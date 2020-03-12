#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	int T; cin >> T;
	while(T--) {
		int r, g, b; cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		int ans = 0;
		if(a[2] >= a[1] + a[0]) ans = a[1] + a[0];
		else {
			ans = a[0] + (a[1] + a[2] - a[0]) / 2;
		}
		cout << ans << endl;
	}
	return 0;
}
