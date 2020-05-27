#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long x;
	cin >> n >> x;

	vector<long long> d(n * 2);
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	for(int i = 0; i < n; ++i) {
		d[i + n] = d[i];
	}

	n = n + n;

	vector<long long> sum(n);
	sum[0] = d[0] * (d[0] + 1) / 2;
	for(int i = 0; i + 1 < n; ++i) {
		sum[i + 1] = sum[i] + d[i + 1] * (d[i + 1] + 1) / 2; 
	}
	vector<long long> pre(n);
	pre[0] = d[0];
	for(int i = 0; i + 1 < n; ++i) {
		pre[i + 1] = pre[i] + d[i + 1];
	}

	int cur = -1;
	long long ans = 0;

	for(int i = 0; i < n; ++i) {
		while(cur + 1 < n && pre[i] - (cur >= 0 ? pre[cur] : 0) > x) {
			cur += 1;
		}
		long long tmp = sum[i] - (cur >= 0 ? sum[cur] : 0);
		if(cur >= 0) {
			long long delta = x - (pre[i] - (cur >= 0 ? pre[cur] : 0));
			long long v = d[cur];
			long long add = (v + v - delta + 1) * delta / 2;
			ans = max(ans, tmp + add);
		} else {
			ans = max(ans, tmp);
		}
	}

	cout << ans << '\n';

	return 0;
}
