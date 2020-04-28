#include <bits/stdc++.h>

using namespace std;

class EllysDifferentPrimes {
	public:

	vector<int> pri;
	vector<bool> mark;
	vector<int> p;

	void init() {
		int m = 50123467;
		mark.resize(m + 1);

		for(int i = 2; i <= m; ++i) {
			if(!mark[i]) {
				pri.emplace_back(i);
			}

			for(int j = 0; j < pri.size() && i * pri[j] <= m; ++j) {
				mark[i * pri[j]] = true;

				if(i % pri[j] == 0) {
					break;
				}
			}
		}

		auto check = [&] (int x) {
			vector<int> vis;
			vis.resize(10);

			while(x) {
				++vis[x % 10];

				if(vis[x % 10] > 1) {
					return false;
				}

				x /= 10;
			}

			return true;
		};

		for(int i : pri) {
			if(check(i)) {
				p.emplace_back(i);
			}
		}
	}
	int getClosest(int N) {
		init();

		auto it = lower_bound(p.begin(), p.end(), N);

		int ans = *it;

		if(it != p.begin()) {
			int x = *--it;

			if(N - x <= ans - N) {
				ans = x;
			}
		}

		return ans;
	}
};
