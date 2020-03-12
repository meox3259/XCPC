#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a;
	a.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll l = -1'000'000'000'000'000'001LL, r = 1'000'000'000'000'000'001LL, ans = -1;
	while(r - l > 1) {
		ll Mid = l + r >> 1LL;
		ll cnt = 0;
		for(int i = 0; i < n; ++i) {
			int L = i, R = n;
			while(R - L > 1) {
				int mid = L + R >> 1;
				if(a[i] * a[mid] <= Mid) {
					if(a[i] < 0) {
						R = mid;
					} else {
						L = mid;
					}
				} else {
					if(a[i] < 0) {
						L = mid;
					} else {
						R = mid;
					}
				}
			}
			if(a[i] < 0) {
				cnt += n - R;
			} else {
				cnt += L - i;
			}
		}
		if(cnt < k) {
			l = Mid;
		} else {
			r = ans = Mid;	
		}
	}
	cout << ans << '\n';
	return 0;
}
