#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if(a == 1 && b == 0 && c == 0) {
		cout << "YES" << '\n';
		cout << 0 << '\n';
		return 0;
	}

	if(a <= b + c) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		cout << min(2 * (b + c) + 1, a + b + c) << '\n';
	}

	return 0;
}
