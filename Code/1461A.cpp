#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			if (i % 3 == 0) {
				cout << 'a';
			}
			if (i % 3 == 1) {
				cout << 'b';
			}
			if (i % 3 == 2) {
				cout << 'c';
			}
		}
		cout << '\n';
	}
	return 0;
}
