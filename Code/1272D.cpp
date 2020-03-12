#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), pre(n), suf(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pre[0] = suf[n - 1] = 1;
	for(int i = 0; i < n - 1; ++i) {
		if(a[i + 1] > a[i]) {
			pre[i + 1] = pre[i] + 1;
		} else {
			pre[i + 1] = 1;
		}
	}
	for(int i = n - 2; ~i; --i) {
		if(a[i + 1] > a[i]) {
			suf[i] = suf[i + 1] + 1;
		} else {
			suf[i] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, pre[i]);
	}
	for(int i = 1; i < n - 1; ++i) {
		if(a[i - 1] < a[i + 1]) {
			ans = max(ans, pre[i - 1] + suf[i + 1]);
		}
	}
	cout << ans << '\n';
	return 0;
}
