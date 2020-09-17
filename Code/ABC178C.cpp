#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	int n;
	cin >> n;

	if(n == 0) {
		cout << 0 << '\n';
		exit(0);
	}	

	long long x = 1;
	for(int i = 0; i < n; ++i) {
		x = x * 10 % P;
	}

	long long y = 2;
	for(int i = 0; i < n; ++i) {
		y = y * 9 % P;
	}

	long long z = 1;
	for(int i = 0; i < n; ++i) {
		z = z * 8 % P;
	}

	cout << (x - y + z + P) % P << '\n';

	return 0;
}
