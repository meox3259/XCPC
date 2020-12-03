#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		
		sort(a.begin(), a.end());

		cout << min(n - 2, a[n - 2] - 1) << '\n';
	}

	return 0;
}
