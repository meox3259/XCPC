#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if(a > 9 || b > 9) {
		cout << -1 << '\n';
	} else {
		cout << a * b << '\n';
	}

	return 0;
}