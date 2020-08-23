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
		if(n >= k) {
			cout << (k % 2 != n % 2) << '\n'; 
		} else {
			cout << k - n << '\n';
		}
	}

	return 0;
}
