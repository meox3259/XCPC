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
		cin >> n;

		vector<long long> a;
		a.resize(n);

		vector<long long> b;
		b.resize(n);

		long long sum = 0;

		for(int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}

		if(n == 1) {
			cout << a[0] << '\n';
			continue;
		}

		for(int i = 0; i < n; ++i) {
			sum += max(0LL, a[(i + 1) % n] - b[i]);
		}

		long long ans = inf;

		for(int i = 0; i < n; ++i) {
			long long tmp = sum;
			tmp -= max(0LL, a[(i + 1) % n] - b[i]);
			tmp += a[(i + 1) % n];

			ans = min(ans, tmp);
		}

		cout << ans << '\n';
	}

	return 0;
}
