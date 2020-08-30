#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long ans = 0;
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		ans = (ans + sum * a[i]) % P;
		sum = (sum + a[i]) % P;
	}

	cout << ans << '\n';

	return 0;
}
