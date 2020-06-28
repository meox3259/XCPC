#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<long long> b(n);
	vector<long long> l(n);
	vector<long long> u(n);
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> b[i] >> l[i] >> u[i];
		sum += b[i] * l[i];
	}

	auto calc = [&] (int i) {
		return b[i] * l[i] + (x - b[i]) * u[i];
	};

	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&] (int i, int j) {
		return calc(i) > calc(j);
	});

	vector<long long> pre(n);
	pre[0] = calc(id[0]);
	for(int i = 0; i + 1 < n; ++i) {
		pre[i + 1] = pre[i] + calc(id[i + 1]);
	}

	long long ans = 1LL * n * x;

	for(int i = 0; i < n; ++i) {
		int j = id[i];
		int left = -1;
		int right = n;
		int cur = n;
		while(right - left > 1) {
			int mid = left + right >> 1;
			int p = mid - 1 + (mid >= i + 1);
			if((p >= 0 ? pre[p] : 0) + (mid - 1 < i ? calc(j) : 0) >= sum) {
				right = cur = mid;
			} else {
				left = mid;
			}
		}

		left = -1;
		right = x + 1;
		int pos = x;
		while(right - left > 1) {
			int mid = left + right >> 1;
			long long add = l[j] * min(1LL * mid, b[j]) + u[j] * max(0LL, mid - b[j]);
			int p = cur >= i + 1 ? cur : cur - 1;
			if(add + (p >= 0 ? pre[p] : 0) - (cur >= i + 1 ? calc(j) : 0) >= sum) {
				right = pos = mid;
			} else {
				left = mid;
			}
		}
		ans = min(ans, 1LL * cur * x + pos);
	}	

	cout << ans << '\n';

	return 0;
}
