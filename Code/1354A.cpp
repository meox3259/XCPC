#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a <= b) {
			cout << b << '\n';
		} else if(c <= d) {
			cout << -1 << '\n';
		} else {
			a -= b;
			long long t = c - d;
			cout << (a + t - 1) / t * c + b << '\n';
		}
	}

	return 0;
}
