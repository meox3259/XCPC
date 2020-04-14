#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int d, m;
		cin >> d >> m;

		int b = 1;
		int c = 1;

		while(b * 2 <= d) {
			b = b * 2;
			++c;
		}

		long long x = d - b + 2;

		for(int i = 0; i < c - 1; ++i) {
			x = x * ((1 << i) + 1) % m;
		}

		cout << (x - 1 + m) % m << '\n';
	}

	return 0;
}
