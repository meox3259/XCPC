#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	long long x = max(a * c, b * d);
	long long y = max(a * d, b * c);

	cout << max(x, y) << '\n';

	return 0;
}
