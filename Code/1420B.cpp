#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long ans = 0;
		vector<int> sum(32);
		for(int i = 0; i < n; ++i) {
			int bit = -1;
			for(int j = 31; j >= 0; --j) {
				if(a[i] >> j & 1) {
					bit = j;
					break;
				}
			}
			if(bit >= 0) {
				ans += sum[bit];
				sum[bit] += 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
