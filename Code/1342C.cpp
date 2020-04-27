#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int a, b, q;
		cin >> a >> b >> q;

		if(a > b) {
			swap(a, b);
		}
	
		int c = a * b / __gcd(a, b);

		while(q--) {
			long long l, r;
			cin >> l >> r;
		
			long long ans = r - l + 1;

			for(int i = 1; i < b; ++i) {
				if(l <= i && i <= r) {
					--ans;
				}
			}

			l = max(l, 1LL * b);

			for(int i = 0; i < b; ++i) {
				long long x = l - i - 1;
				long long y = r - i;
				ans -= y / c - x / c;
			}

			cout << ans << ' ';
		}

		cout << '\n';
	}

	return 0;
}
