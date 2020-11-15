#include <bits/stdc++.h>

using namespace std;

int main() {
	double sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;

	if(sx > gx) {
		swap(sx, gx);
		swap(sy, gy);
	}

	double d = gx - sx;

	d = d / (gy + sy) * sy;

	cout << fixed << setprecision(10);
	cout << sx + d << '\n';

	return 0;
}
