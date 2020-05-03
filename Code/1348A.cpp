#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;
		long long ans = 0;
		ans += 1LL << n;
		for(int i = 1; i < n / 2; ++i) {
			ans += 1LL << i;
		}
		for(int i = n / 2; i < n; ++i) {
			ans -= 1LL << i;
		}
		cout << ans << '\n';
	}

	return 0;
}
