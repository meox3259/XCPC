#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;

	int ans = 0;

	for(long long i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			int cnt = 0;
			while(n % i == 0) {
				n /= i;
				cnt += 1;
			}
			int j = 1;
			while(cnt >= j) {
				cnt -= j;
				j += 1;
				ans += 1;
			}
		}
	}

	if(n > 1) {
		ans += 1;
	}

	cout << ans << '\n';

	return 0;
}
