;#include <bits/stdc++.h>
using namespace std;
class BinaryHeapLeaf {
	public:
		vector <int> maxDiff(int n) {
			int dep = n, c = 0;
			for(int d = 0; ; ++d) {
				int low = 1 << d, high = 1 << (d + 1);
				if(low > n) {
					break;
				}
				for(int i = low; i < high; ++i) {
					if(i <= n && i * 2 > n) {
						++c;
                        dep = min(dep, d);
					} 
				}
			}
			return {c, n - dep};
		}
};
