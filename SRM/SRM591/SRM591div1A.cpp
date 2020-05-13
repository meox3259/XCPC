#include <bits/stdc++.h>

using namespace std;

class TheTree {
	public:
	int maximumDiameter(vector <int> cnt) {
		int n = cnt.size();
		int ans = n;

		--cnt[n - 1];

		for(int i = 0; i < n; ++i) {
			if(cnt[i] > 0) {
				int lca = -1;
				for(int j = min(n - 2, i); j >= 0; --j) {
					if(cnt[j] == 1) {
						lca = j;
						break;
					}
				}
				ans = max(ans, n - 1 - lca + i - lca);
			}
		}

		return ans;
	}
};
