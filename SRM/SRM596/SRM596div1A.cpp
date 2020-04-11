#include <bits/stdc++.h>

using namespace std;

class IncrementAndDoubling {
	public:
	int getMin(vector <int> a) {
		int ans = 0;
		int mx = 0;

		for(int i : a) {
			for(int j = 30; j >= 0; --j) {
				if(i >> j & 1) {
					mx = max(mx, j);
					break;
				}
			}

			ans += __builtin_popcount(i);
		}

		return ans + mx;
	}
};
