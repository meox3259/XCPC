#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> x;
	vector<int> y;
	x.resize(n);
	y.resize(n);
	double X = 0;
	double Y = 0;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		X += x[i];
		Y += y[i];
	}
	X /= n;
	Y /= n;
	auto Rand = [&] () {
		return rand() % 10000 / 10000.0;
	};
	auto calc = [&] (double X, double Y) {
		double ret = 0;
		for(int i = 0; i < n; ++i) {
			ret = max(ret, sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i])));
		}
		return ret;
	};
	double T = 10000.0;
	while(T > 0.0000001) {
		double new_X = X + T * (Rand() * 2 - 1.0);
		double new_Y = Y + T * (Rand() * 2 - 1.0);	
		if(calc(X, Y) > calc(new_X, new_Y)) {
			X = new_X;
			Y = new_Y;
		}
		T *= 0.999991;
	}
	cout << fixed << setprecision(15);
	cout << calc(X, Y) << '\n';
	return 0;
}
