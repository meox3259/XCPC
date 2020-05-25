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
		sort(a.begin(), a.end());
		int ans = a[1] - a[0];
		for(int i = 0; i + 1 < n; ++i) {
			ans = min(ans, a[i + 1] - a[i]);
		}
		cout << ans << '\n';
	}

	return 0;
}
