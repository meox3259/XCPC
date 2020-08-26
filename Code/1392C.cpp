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
		for(int i = 0; i + 1 < n; ++i) {
			if(a[i + 1] < a[i]) {
				ans += a[i] - a[i + 1];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
