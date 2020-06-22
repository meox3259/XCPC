#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int n;
		cin >> n;

		if(n == 1) {
			cout << "FastestFinger" << '\n';
		} else if(n % 2 == 1) {
			cout << "Ashishgup" << '\n';
		} else {
			int two = 0;
			while(n % 2 == 0) {
				n /= 2;
				two += 1;
			}

			int div = 0;

			for(int i = 2; i * i <= n; ++i) {
				if(n % i == 0) {
					while(n % i == 0) {
						n /= i;
						div += 1;
					}
				}
			}

			if(n > 1) {
				div += 1;
			}

			if(two == 1) {
				if(div != 1) {
					cout << "Ashishgup" << '\n';
				} else {
					cout << "FastestFinger" << '\n';
				}
			} else {
				if(div > 0) {
					cout << "Ashishgup" << '\n';
				} else {
					cout << "FastestFinger" << '\n';
				}
			}
		}
	}

	return 0;
}
