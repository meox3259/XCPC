#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int T;
	cin >> T;
	while(T--) {
		ll n;
		int m;
		cin >> n >> m;
		vector<int> cnt;
		cnt.resize(70);
		ll sum = 0;
		for(int i = 0; i < m; ++i) {
			ll x;
			cin >> x;
			sum += x;
			int bit = 0;
			while(x > 1) {
				++bit;
				x >>= 1LL;
			}
			++cnt[bit];
		}
		if(sum < n) {
			cout << -1 << '\n';
			continue;
		}
		int ans = 0;
		for(int i = 0; i < 63; ++i) {
			if(n >> i & 1LL) {
				int j = i;
				while(!cnt[j]) {
					++j;
				}
				--cnt[j];
				while(j != i) {
					--j;
					++cnt[j];
					++ans;
				}
			}
			cnt[i + 1] += cnt[i] / 2;
		}
		cout << ans << '\n';
	}
	return 0;
}
