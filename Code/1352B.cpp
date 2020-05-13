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

		if(n % 2 == 0) {
			if(k % 2 == 1) {
				if(k * 2 > n) {
					cout << "NO" << '\n';
				} else {
					cout << "YES" << '\n';
					for(int i = 1; i < k; ++i) {
						cout << 2 << ' ';
					}
					cout << n - k * 2 + 2 << '\n';
				}
			} else {
				if(k > n) {
					cout << "NO" << '\n';
				} else {
					cout << "YES" << '\n';
					for(int i = 1; i < k; ++i) {
						cout << 1 << ' ';
					}
					cout << n - k + 1 << '\n';
				}
			}
		} else {
			if(k % 2 == 0) {
				cout << "NO" << '\n';
			} else {
				if(k > n) {
					cout << "NO" << '\n';
				} else {
					cout << "YES" << '\n';
					for(int i = 1; i < k; ++i) {
						cout << 1 << ' ';
					}
					cout << n - k + 1 << '\n';
				}
			}
		}
	}

	return 0;
}
