#include <bits/stdc++.h>

using namespace std;

class BinPacking {
	public:
	int minBins(vector <int> item) {
		int cnt = 0;

		for(auto x : item) {
			if(x == 100) {
				++cnt;
			}
		}

		int ret = item.size();

		for(int c = 0; c <= cnt; ++c) {
			int t = c;

			vector<int> v;

			for(auto x : item) {
				if(x == 100 && t > 0) {
					--t;
				} else {
					v.emplace_back(x);
				}
			}

			int tmp = (c + 2) / 3;

			sort(v.begin(), v.end());

			int m = v.size();

			tmp += m;

			vector<bool> vis;
			vis.resize(m, false);

			for(int i = m - 1; i >= 0; --i) {
				if(!vis[i]) {
					for(int j = m - 1; j >= 0; --j) {
						if(j != i && !vis[j] && v[i] + v[j] <= 300) {
							vis[i] = true;
							vis[j] = true;
							--tmp;

							break;
						}
					}
				}
			}

			ret = min(ret, tmp);
		}

		return ret;
	}
};

