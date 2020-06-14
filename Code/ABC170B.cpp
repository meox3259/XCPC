#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	bool ok = false;

	for(int i = 0; i <= x; ++i) {
		if(2 * i + 4 * (x - i) == y) {
			ok = true;
		}
	}

	if(ok) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}
