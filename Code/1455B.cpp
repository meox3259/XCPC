#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		int x;
		cin >> x;
		
		int cur = 1;
		int sum = 0;
		int ans = 2000;
		for(int i = 1; i <= 2000; ++i) {
			sum += i;
			if(sum >= x) {
				if((sum & 1) == (x & 1)) {
					ans = min(ans, i);
				} else {
					if(sum - x == 1) {
						ans = min(ans, i + 1);
					} else {
						ans = min(ans, i);
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
