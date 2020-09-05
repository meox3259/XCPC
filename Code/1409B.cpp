#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		long long d = a - x + b - y;
		if(n >= d) {
			cout << 1LL * x * y << '\n';
		} else {
			long long ans = 1000000000000000000;
			long long ta = a;
			long long tb = b;
			long long tn = n;
			long long d = min(a - x, tn);
			ta -= d;
			tn -= d;
			tb -= min(b - y, tn);
			ans = min(ans, ta * tb);
			ta = a;
			tb = b;
			tn = n;
			d = min(b - y, tn);
			tb -= d;
			tn -= d;
			ta -= min(a - x, tn);
			ans = min(ans, ta * tb);
			cout << ans << '\n';
		}
	}

	return 0;
}
