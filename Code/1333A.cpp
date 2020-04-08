#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n, m;
		cin >> n >> m;

		for(int i = 1; i <= n - 1; ++i) {
			for(int j = 0; j < m; ++j) {
				cout << 'B';
			}

			cout << '\n';
		}

		for(int j = 0; j < m - 1; ++j) {
			cout << 'W';
		}

		cout << 'B' << '\n';
	}

	return 0;
}
