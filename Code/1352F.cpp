#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;

		int last = -1;

		if(a > 0 && c > 0) {
			--b;
		}

		if(a > 0) { 
			for(int i = 0; i <= a; ++i) {
				cout << 0;
			}
			last = 0;
		}

		if(c > 0) {
			for(int i = 0; i <= c; ++i) {
				cout << 1;
			}
			last = 1;
		}

		if(last == -1) {
			cout << 0;
			last = 0;
		}

		for(int i = 0; i < b; ++i) {
			cout << (last ^ 1);
			last ^= 1;
		}

		cout << '\n';
	}

	return 0;
}
