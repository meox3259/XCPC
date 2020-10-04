#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k, z;
		cin >> n >> k >> z;

		vector<long long> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		vector<long long> pre(n + 1);
		for(int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + a[i]; 
		}

		if(z == 0) {
			cout << pre[k + 1] << '\n';
			continue;
		}

		long long ans = a[0];
		long long mx = 0;
		for(int i = 1; i < n && i <= k; ++i) {
			mx = max(mx, a[i - 1] + a[i]);
			if((k - i) % 2 == 0) {
				ans = max(ans, pre[i + 1] + mx * min(z, (k - i) / 2));
			} else {
				long long d = min(z, (k - i + 1) / 2);
				ans = max(ans, pre[i + 1] + a[i - 1] * d + a[i] * (d - 1));
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
