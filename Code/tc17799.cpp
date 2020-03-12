#include <bits/stdc++.h>
using namespace std;
class CheatingAfterTests {
	public:
		int cheat(vector <int> a) {
			int n = a.size(), ans = 0;
			for(int i = 0; i < n; ++i) {
				int tmp = 0;
				int one = a[i] % 10;
				for(int j = 0; j < n; ++j) {
					if(j != i) {
						tmp += a[j];
					}
				}
				ans = max(ans, tmp + a[i] - one + 9);
				if(a[i] / 10) {
					ans = max(ans, tmp + 90 + one);
				}
			}
			return ans;
		}
};
