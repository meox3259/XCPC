#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		long long a, b;
		cin >> a >> b;
		long long d = b - a + 1;
		ans += 1LL * (a + b) * d / 2;
	}
	
	cout << ans << '\n';

	return 0;
}
