#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, c;

	cin >> a >> b >> c;

	c -= a + b;

	if(c < 0) {
		cout << "No" << '\n';
	} else if(c * c > 4LL * a * b) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}
	return 0;
}
