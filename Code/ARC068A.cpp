#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x;
	cin >> x;

	long long ans = x / 11 * 2;

	if(x % 11 > 6) {
		ans += 2;
	} else if(x % 11 > 0) {
		ans += 1;
	}
	cout << ans << '\n';
		
	return 0;

}
