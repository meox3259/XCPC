#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T --) {
		int n;
		cin >> n;

		vector<long long> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}

		vector<long long> cnt(61);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 61; ++j) {
				if (x[i] >> j & 1) {
					cnt[j] ++;
				}
			}
		}

		long long ans = 0;
		for (int j = 0; j < n; ++j) {
			long long sa = 0;
			for (int b = 0; b < 61; ++b) {
				if (x[j] >> b & 1) {
					sa = (sa + (1LL << b) % P * cnt[b] % P) % P;	
				}
			}	
			long long sb = 0;
			for (int b = 0; b < 61; ++b) {
				if (x[j] >> b & 1) {
					sb = (sb + (1LL << b) % P * n % P) % P;	
				} else {
					sb = (sb + (1LL << b) % P * cnt[b] % P) % P;
				}
			}
			ans = (ans + sa * sb) % P;
		}

		cout << ans << '\n';
	}

	return 0;
}
