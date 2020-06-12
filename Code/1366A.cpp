#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		long long a, b;
		cin >> a >> b;
		if(a > b) {
			swap(a, b);
		}
		long long ans = min(a, b);
		ans = min(ans, (a + b) / 3);
		cout << ans << '\n';
	}

	return 0;
}
