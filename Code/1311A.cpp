#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int a, b;
		cin >> a >> b;
		if(a == b) {
			cout << 0 << '\n';
		} else if(a < b) {
			if((a & 1) != (b & 1)) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}
		} else {
			if((a & 1) == (b & 1)) {
				cout << 1 << '\n';
			} else {
				cout << 2 << '\n';
			}
		}
	}
	return 0;
}
