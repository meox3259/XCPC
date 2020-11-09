#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<long long> pre(n + 1);
	vector<long long> mx(n + 1);
	for(int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + a[i];
		mx[i + 1] = max(mx[i], pre[i + 1]);
	}

	long long cur = 0;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = max(ans, cur + mx[i]);
		cur += pre[i];
	}

	cout << ans << '\n';

	return 0;
}
