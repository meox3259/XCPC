#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;

	long long ans = 0;

	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= k; ++j) {
			int t = __gcd(i, j);
			for(int x = 1; x <= k; ++x) {
				ans += __gcd(t, x);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
