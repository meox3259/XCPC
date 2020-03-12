#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	vector<int> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int> ());
	int l = 0, r = 200005, lim = 0;
	while(r - l > 1) {
		int mid = l + r >> 1;
		long long cnt = 0;
		for(int i = 0; i < n; ++i) {
			int L = -1, R = n, p = -1;
			while(R - L > 1) {
				int Mid = L + R >> 1;
				if(a[Mid] + a[i] >= mid) {
					L = p = Mid;
				} else {
					R = Mid;
				}
			}
			cnt += p + 1;
		}
		if(cnt >= m) {
			l = lim = mid;
		} else {
			r = mid;
		}
	}
	vector<long long> pre;
	pre.resize(n);
	pre[0] = a[0];
	for(int i = 0; i < n - 1; ++i) {
		pre[i + 1] = pre[i] + a[i + 1];
	}
	long long ans = 0;
	long long sum = 0;
	for(int i = 0; i < n; ++i) {
		int l = -1, r = n, p = -1;
		while(r - l > 1) {
			int mid = l + r >> 1;
			if(a[mid] + a[i] >= lim) {
				l = p = mid;
			} else {
				r = mid;
			}
		}
		if(p != -1) {
			ans += 1LL * a[i] * (p + 1) + pre[p];
			sum += p + 1;
		}
	}
	cout << ans - 1LL * (sum - m) * lim << '\n';
	return 0;
}
