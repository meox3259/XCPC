#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, x;
	cin >> a >> b >> x;

	long long ans = 0;

	for(int bit = 1; bit <= 10; ++bit) {
		long long rem = x - b * bit;
		
		if(rem > 0) {
			int cnt = 0;
		
			long long tmp = rem / a;

			while(tmp) {
				++cnt;
				tmp /= 10;
			}

			if(cnt <= bit) {
				ans = max(ans, rem / a);
			} else {
				long long x = 1;
				for(int i = 0; i < bit - 1; ++i) {
					x = x * 10;
				}

				ans = max(ans, x);

			}
		}
	
	}

	cout << min(ans, 1000000000LL) << '\n';

	return 0;
}
