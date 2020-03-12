#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, a, b;
	cin >> n >> a >> b;

	cout << (b - a) / 2 + (b - a) % 2 * min(a, n - b + 1) << '\n';

	return 0;
}
