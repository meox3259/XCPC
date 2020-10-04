#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000000000000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long k;
		cin >> n >> k;

		int l1, r1;
		cin >> l1 >> r1;

		int l2, r2;
		cin >> l2 >> r2;

		if(l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
		}

		if(r1 >= l2) {
			long long x = min(r1, r2) - l2;
			k -= x * n;
		}

		if(k <= 0) {
			cout << 0 << '\n';
			continue;
		}

		if(l2 <= r1) {
			long long d = abs(r2 - r1) + abs(l2 - l1);
			long long tmp = min(d * n, k);
			long long ans = 0;
			k -= tmp;
			ans += tmp;
			ans += k * 2;
			cout << ans << '\n';
		} else {
			long long cost = l2 - r1;	
			long long d = r2 - l1;
			long long ans = inf;
			for(int i = 1; i <= n; ++i) {
				long long tmp = 0;
				long long t = k;
				tmp += cost * i;
				long long delta = min(t, d * i);
				t -= delta;
				tmp += delta;
				tmp += t + t;
				ans = min(ans, tmp);
			}
			cout << ans << '\n';
		}
	}

	return 0;
}
