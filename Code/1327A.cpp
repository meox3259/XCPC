#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long n, k;
		cin >> n >> k;

		long long s = k * k;

		if(n % 2 != k % 2) {
			cout << "NO" << '\n';
			continue;
		}

		if(s > n) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}
