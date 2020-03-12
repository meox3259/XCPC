#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a;
	vector<int> cnt;
	a.resize(n);
	cnt.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		while(a[i] % 2 == 0) {
			a[i] /= 2;
			++cnt[i];
		}
	}
	for(int i = 0; i < n; ++i) {
		if(cnt[i] != cnt[0]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	long long v = 1;
	for(int i = 0; i < cnt[0] - 1; ++i) {
		v = v * 2;
	}
	for(auto x : a) {
		v = v * x / __gcd(v, 1LL * x);	
		if(v > m) {
			cout << 0 << '\n';
			return 0;
		}
	}
	int ans = (m / v + 1) / 2;
	cout << ans << '\n';
	return 0;
}
