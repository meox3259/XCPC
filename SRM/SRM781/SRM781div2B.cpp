#include <bits/stdc++.h>

using namespace std;

class NicePartition {
	public:
		int minCost(vector <int> H) {
			int ans = 0;
			int n = H.size() / 2;

			sort(H.begin(), H.end());

			for(int i = 0; i < n; ++i) {
				ans += H[i + n] - H[i];
			}

			return ans;
		}
};
