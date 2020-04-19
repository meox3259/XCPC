#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	int n, k;
	cin >> n >> k;

	long long ans = 0;

	for(int i = k; i <= n + 1; ++i) {
		long long l = 1LL * i * (i - 1) / 2;
		long long r = 1LL * (n + n - i + 1) * i / 2;
		ans = (ans + r - l + 1) % P;
	}

	cout << ans << '\n';

	return 0;
}
