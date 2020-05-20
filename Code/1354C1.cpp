#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		double deg = acos(-1) / (2. * n);
		double s = 1. / tan(deg);

		cout << fixed << setprecision(10);
		cout << s << '\n';

	}

	return 0;
}
