#include <bits/stdc++.h>
using namespace std;
int main() {
	srand(114514);
	int n, k;
	cin >> n >> k;
	vector<int> x;
	vector<int> y;
	vector<int> c;
	x.resize(n);
	y.resize(n);
	c.resize(n);
	double X = 0;
	double Y = 0;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> c[i];
		X += x[i];
		Y += y[i];
	}
	X /= n;
	Y /= n;
	auto Rand = [&] () {
		return rand() % 10000 / 10000.0;
	};
	auto calc = [&] (double X, double Y) {
		vector<double> t;
		t.resize(n);
		for(int i = 0; i < n; ++i) {
			t[i] = 1.0 * c[i] * sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
		}
		nth_element(t.begin(), t.begin() + k - 1, t.end());
		return t[k - 1];
	};
	double T = 10000.0;
	while(T > 0.0000001) {
		double new_X = X + T * (Rand() * 2 - 1.0);
		double new_Y = Y + T * (Rand() * 2 - 1.0);	
		if(calc(X, Y) > calc(new_X, new_Y)) {
			X = new_X;
			Y = new_Y;
		}
		T *= 0.99991;
	}
	for(int i = 0; i < 10000; ++i) {
		double new_X = X + (Rand() * 2 - 1.0);
		double new_Y = Y + (Rand() * 2 - 1.0);
		if(calc(X, Y) > calc(new_X, new_Y)) {
			X = new_X;
			Y = new_Y;
		}
	}
	cout << fixed << setprecision(15);
	cout << calc(X, Y) << '\n';
	return 0;
}
