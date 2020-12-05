#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long x = 1;
	for (int i = 1; i <= n; ++i) {
		x = x * i / __gcd(x, 1LL * i);
	}

	cout << x + 1 << '\n';

	return 0;
}
