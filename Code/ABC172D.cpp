#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> f(n + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			f[j] += 1;
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += 1LL * i * f[i];
	}

	cout << ans << '\n';

	return 0;
}
