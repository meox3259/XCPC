#include <bits/stdc++.h>

using namespace std;

int main() {
	long long x;
	cin >> x;

	long long y = 100;

	int ans = 0;
	while(y < x) {
		y += y / 100;
		++ans;
	}

	cout << ans << '\n';

	return 0;
}
