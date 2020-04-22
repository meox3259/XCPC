#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		long long t = 2;
		long long x = -1;

		while(1) {
			long long y = 2 * t - 1;

			if(n / y == 0) {
				break;
			}

			if(n % y == 0) {
				x = n / y;
				break;
			}

			t = t * 2;
		}

		cout << x << '\n';
	}

	return 0;
}
