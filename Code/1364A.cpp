#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		int ans = -1;
		int sum = 0;
		int u = -1;
		int v = -1;
		for(int i = 0; i < n; ++i) {
			sum = (sum + a[i]) % x;
			if(sum != 0) {
				ans = max(ans, i + 1);
			}
			if(u == -1 && sum != 0) {
				u = sum;
				v = i;
			}
			if(u != -1 && sum != u) {
				ans = max(ans, i - v);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
