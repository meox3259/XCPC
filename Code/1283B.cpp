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
		int t = n % k;
		cout << n - t + min(k / 2, t) << '\n';  
	}

	return 0;
}
