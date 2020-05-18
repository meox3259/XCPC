#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	long long ans = 0;

	vector<long long> pre(b + c + d + 1);
	for(int i = a; i <= b; ++i) {
		pre[i + b] += 1;
		pre[i + c + 1] -= 1;
	}

	for(int i = 0; i < b + c + d; ++i) {
		pre[i + 1] += pre[i];
	}

	for(int i = 0; i < b + c + d; ++i) {
		pre[i + 1] += pre[i];
	}

	for(int i = c; i <= d; ++i) {
		ans += pre[b + c + d] - pre[i];
	}

	cout << ans << '\n';

	return 0;
}
