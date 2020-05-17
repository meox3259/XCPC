#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B, H, M;
	cin >> A >> B >> H >> M;

	double a = A * A;
	double b = B * B;

	cout << fixed << setprecision(10);

	double da = 30. * H + 1. * M / 2.;
	double db = 6. * M; 

	double deg = abs(da - db);

	deg = min(deg, 360. - deg);

	cout << sqrt(a + b - 2. * A * B * cos(deg / 180. * acos(-1))) << '\n';

	return 0;
}
