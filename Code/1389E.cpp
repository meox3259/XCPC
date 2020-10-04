#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int m, d, w;
		cin >> m >> d >> w;

		long long up = min(m, d);
		if((d - 1) % w == 0) {
			cout << up * (up - 1) / 2 << '\n';	
		} else {
			long long ans = 0;
			long long tmp = w / __gcd(d - 1, w);
			long long x = up % tmp;
			long long y = tmp - x;
			long long div = up / tmp;
			ans += x * (div + 1) * (div + 1);
			ans += y * div * div;
			ans -= up;
			ans /= 2;
			cout << ans << '\n';
		}
	}
		
	return 0;
}
