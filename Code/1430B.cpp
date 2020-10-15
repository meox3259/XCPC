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

		vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		sort(a.begin(), a.end(), greater<int> ());
		long long ans = 0;
		for(int i = 0; i < k + 1; ++i) {
			ans += a[i];
		}

		cout << ans << '\n';
	}

	return 0;
}
