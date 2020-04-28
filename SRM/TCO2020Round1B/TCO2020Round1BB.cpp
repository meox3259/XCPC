#include <bits/stdc++.h>

using namespace std;

class EllysWhatDidYouGet {
	public:
	int getCount(int N) {
		int ans = 0;

		auto f = [&] (int x) {
			int ret = 0;

			while(x) {
				ret += x % 10;
				x /= 10;
			}

			return ret;
		};	

		for(int x = 1; x <= 50; ++x) {
			for(int y = 1; y <= 50; ++y) {
				for(int z = 1; z <= 50; ++z) {
					int v = f((1 * x + y) * z);
					bool ok = true;

					for(int i = 2; i <= N; ++i) {
						if(f((i * x + y) * z) != v) {
							ok = false;
							break;
						}
					}

					if(ok) {
						++ans;
					}
				}
			}
		}

		return ans;
	}
};
