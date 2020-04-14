#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long n;
		cin >> n;

		vector<int> ord = { 0, 2, 3, 1 };

		long long t = 1;
		long long s = 0;

		while(1) {
			if(s + t >= (n + 2) / 3) {
				break;
			}

			s += t;
			t <<= 2;
		}

		long long a = t + (n - 1) / 3 - s;
		long long b = 0;

		long long x = a;
		long long y = 1;

		while(x) {
			b += y * ord[x % 4];
			x >>= 2;
			y <<= 2;
		}

		long long c = a ^ b;

		if(b > c) {
			swap(b, c);
		}

		if(n % 3 == 1) {
			cout << a << '\n';
		}

		if(n % 3 == 2) {
			cout << b << '\n';
		}

		if(n % 3 == 0) {
			cout << c << '\n';
		}
	}

	return 0;
}
