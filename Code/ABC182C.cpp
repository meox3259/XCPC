#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<int> b;
	while(n) {
		b.emplace_back(n % 10);
		n /= 10;
	}

	int m = b.size();
	int ans = m;
	for(int i = 0; i < 1 << m; ++i) {
		int sum = 0;
		for(int j = 0; j < m; ++j) {
			if(i >> j & 1) {
				sum += b[j];
			}
		}
		if(sum % 3 == 0) {
			ans = min(ans, m - __builtin_popcount(i));	
		}
	}

	if(ans == m) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}
