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
		if(l + l <= r) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}

	return 0;
}
