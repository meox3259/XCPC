#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int l, r;
		cin >> l >> r;
		if(l + l > r) {
			cout << -1 << ' ' << -1 << '\n';
		} else {
			cout << l << ' ' << l + l << '\n';
		}
	}

	return 0;
}
