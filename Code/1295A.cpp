#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		if(n % 2 == 0) {
			for(int i = 1; i <= n / 2; ++i) {
				cout << 1;
			}
			cout << '\n';
		} else {
			cout << 7;
			for(int i = 1; i <= (n - 3) / 2; ++i) {
				cout << 1;
			}
			cout << '\n';
		}
	}
	return 0;
}
