#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, p, k;
		cin >> n >> p >> k;

		string s;
		cin >> s;

		vector<int> a(n + 2);
		for(int i = 0; i < n; ++i) {
			a[i + 1] = s[i] - '0';
		}

		int x, y;
		cin >> x >> y;

		vector<int> cnt(k);
		for(int i = p; i <= n; ++i) {
			cnt[i % k] += (a[i] == 0);
		}

		long long ans = 1000000000000000000;
		for(int i = 0; i <= n - p; ++i) {
			ans = min(ans, 1LL * i * y + 1LL * x * cnt[(i + p) % k]);	
			cnt[(i + p) % k] -= (a[i + p] == 0);
		}

		cout << ans << '\n';
	}

	return 0;
}
