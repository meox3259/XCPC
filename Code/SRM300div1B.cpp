#include <bits/stdc++.h>

using namespace std;

class JumpyNum {
	public:
		int dfs(int low, int high, int cur, int last) {
			if(cur > high / 10) {
				return 0;
			}

			int ret = 0;

			for(int i = 0; i < 10; ++i) {
				if(cur * 10 + i <= high && abs(i - last) >= 2) {
					if(cur * 10 + i >= low) {
						++ret;
					}

					ret += dfs(low, high, cur * 10 + i, i);
				}
			}

			return ret;
		}

		int howMany(int low, int high) {
			return dfs(low, high, 0, -1);
		}
};
