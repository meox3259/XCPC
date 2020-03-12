#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	double ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += 1.0 / i;
	}
	cout << fixed << setprecision(10);
	cout << ans << '\n';
	return 0;
}
