#include <bits/stdc++.h>

using namespace std;

class ORSolitaire {
	public:
		int getMinimum(vector <int> numbers, int goal) {
			int n = numbers.size();

			vector<int> v;

			for(auto x : numbers) {
				if((x & goal) == x) {
					v.emplace_back(x);
				}
			}

			vector<int> cnt;
			cnt.resize(31);

			for(auto x : v) {
				for(int i = 0; i < 31; ++i) {
					if(x >> i & 1) {
						++cnt[i];
					}
				}
			}

			int ans = n;

			for(int i = 0; i < 31; ++i) {
				if(goal >> i & 1) {
					ans = min(ans, cnt[i]);
				}
			}

			return ans;
		}
};
