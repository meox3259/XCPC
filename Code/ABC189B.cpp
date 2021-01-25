#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long x;
	cin >> n >> x;
		
	int ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		long long v, p;
		cin >> v >> p;
		sum += v * p;
		if (sum > x * 100) {
			cout << i + 1 << '\n';
			exit(0);
		}
	}

	cout << -1 << '\n';

	return 0;
}
