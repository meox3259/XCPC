#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll seed = 19992147;
const int maxn = 105;
int n;
int a[maxn];
map<ll, int> mp;
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int S = 0; S < 1 << 15; ++S) {
		ll h = 0;
		for(int i = 1; i <= n; ++i) {
			int t = (a[i] & ((1 << 15) - 1)) ^ S;
			h = h * seed + __builtin_popcount(t);
		}
		mp[h] = S;
	}
	for(int S = 0; S < 1 << 15; ++S) {
		for(int j = 1; j <= 30; ++j) {
			ll h = 0;
			for(int i = 1; i <= n; ++i) {
				int t = ((a[i] & (((1 << 15) - 1) << 15)) >> 15) ^ S;
				h = h * seed + (j - __builtin_popcount(t));
			}
			if(mp.count(h)) {
				printf("%d\n", mp[h] + (S << 15));
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}
