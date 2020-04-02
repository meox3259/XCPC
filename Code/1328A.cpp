#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int a, b;
		cin >> a >> b;

		bool ok = false;

		if(a < b) {
			cout << b - a << '\n';
			continue;
		}

		if(a % b == 0) {
			cout << 0 << '\n';
			continue;
		}

		int t = (a + b - 1) / b;

		cout << t * b - a << '\n';
	}

	return 0;
}
