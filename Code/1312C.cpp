#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e16;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a;
		a.resize(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<ll> b;
		b.resize(n, 0);
		ll t = 1;
		int cnt = 0;
		vector<ll> f;
		f.resize(105);
		for(;;) {
			f[cnt++] = t;
			t = t * k;
			if(t > inf) {
				break;
			}
		}
		bool F = 1;
		while(*max_element(a.begin(), a.end()) != 0) {
			int cnt = 0;
			for(int i = 0; i < n; ++i) {
				if(a[i] % k != 0 && a[i] % k != 1) {
					F = 0;
				}	
				if(a[i] % k == 1) {
					++cnt;
				}
				a[i] /= k;
			}
			if(cnt > 1) {
				F = 0;
			}
		}
		if(F == 1) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
