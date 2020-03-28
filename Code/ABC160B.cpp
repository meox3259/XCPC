#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x;
	cin >> x;

	long long ans = 0;

	ans += (x - x % 500) * 2;

	x %= 500;

	ans += x - x % 5;

	cout << ans << '\n';

	return 0;
}
