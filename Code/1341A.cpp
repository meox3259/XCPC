#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;

		int l = n * (a - b);
		int r = n * (a + b);

		if(r < c - d || l > c + d) {
			cout << "No" << '\n';
		} else {
			cout << "Yes" << '\n';
		}
	}

	return 0;
}
