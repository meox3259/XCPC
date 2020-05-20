#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		cout << fixed << setprecision(10);
		cout << cos(pi / (4. * n)) / sin(pi / (2. * n)) << '\n';
	}

	return 0;
}
