#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		long long a, b, n;
		cin >> a >> b >> n;

		int ans = 0;

		while(a <= n && b <= n) {
			if(a > b) {
				swap(a, b);
			}
			ans += 1;
			a += b;
		}

		cout << ans << '\n';
	}

	return 0;
}
