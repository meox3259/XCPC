#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		int ans = 0;

		cin >> ans;

		ans = ans * 3;

		for(int i = 1; i < n; ++i) {
			int x;
			cin >> x;

			ans = max(ans, x + 1);
		}

		cout << ans + (ans & 1) << '\n';
	}

	return 0;
}
