#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		if (k % 3 == 0) {
			n %= (k + 1);
		}
		if (n % 3 == 0 && n != k) {
			cout << "Bob" << '\n';
		} else {
			cout << "Alice" << '\n';
		}
	}

	return 0;
}
