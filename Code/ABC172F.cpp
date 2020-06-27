#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long Xor = 0;
	for(int i = 2; i < n; ++i) {
		Xor ^= a[i];
	}

	long long S = a[0] + a[1];
	long long d = S - Xor;

	if(d % 2 != 0) {
		cout << -1 << '\n';
		exit(0);
	}

	d >>= 1;

	long long x = 0;
	long long y = 0;

	bool small = false;
	long long must = 0;

	for(int i = 62; i >= 0; --i) {
		if(Xor >> i & 1) {
			must += 1LL << i;
		}
	}

	long long sum = 0;

	for(int i = 60; i >= 0; --i) {
		if(!(Xor >> i & 1)) {
			if(sum + 2LL * (1LL << i) + must <= S) {
				x += 1LL << i;
				y += 1LL << i;
				sum += 2LL * (1LL << i);
			}
		}
	}

	for(int i = 62; i >= 0; --i) {
		if(Xor >> i & 1) {
			if(x + (1LL << i) <= a[0]) {
				x += 1LL << i;
			} else {
				y += 1LL << i;
			}
		}
	}

	if(x <= 0 || y <= 0 || x + y != S || (x ^ y) != Xor || x > a[0]) {
		cout << -1 << '\n';
	} else {
		cout << a[0] - x << '\n';
	}

	return 0;
}
