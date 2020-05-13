#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		long long l = 0;
		long long r = k * 2 + 1;
		long long ans = 0;
		while(r - l > 1) {
			long long mid = (l + r) / 2; 
			if(mid - mid / n > k) {
				r = mid;
			} else {
				l = ans = mid;
			}
		}

		if(ans % n == 0) {
			--ans;
		}
		cout << ans << '\n';
	}

	return 0;
}
