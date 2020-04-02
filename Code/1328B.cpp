#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		int p = 0;

		while((1LL * p * (p + 1) / 2) < k) {
			++p;
		}

		string ans(n, 'a');

		ans[n - p - 1] = 'b';

		k -= 1LL * p * (p - 1) / 2;

		ans[n - k] = 'b';

		cout << ans << '\n';
	}

	return 0;
}
