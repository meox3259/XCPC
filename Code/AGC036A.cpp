#include <bits/stdc++.h>

using namespace std;

const long long m = 1000000000;

int main() {
	long long s;
	cin >> s;

	long long x1, y1;
	long long x2, y2;

	long long d = (m - s % m) % m;			

	x2 = 1;
	y1 = d;
	
	s += d;

	x1 = m;
	y2 = s / m;

	cout << 0 << ' ' << 0 << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';

	return 0;
}
