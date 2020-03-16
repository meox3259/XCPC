#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long a, b;
	cin >> n >> a >> b;

	vector<long long> x;
	x.resize(n);

	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	long long ans = 0;

	for(int i = 0; i + 1 < n; ++i) {
		ans += min((x[i + 1] - x[i]) * a, b);
	}

	cout << ans << '\n';

	return 0;

}
