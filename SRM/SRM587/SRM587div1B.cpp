#include <bits/stdc++.h>

using namespace std;

class TriangleXor {
	public:
	int theArea(int W) {
		double ret = .5 * W * (W + 1);
		double mul = -1.;
		for(int i = 1; i <= W; ++i) {
			ret += .5 * W * W / (W + i) * (W + 1 - i) * 2. * mul;
			mul = -mul;
		}
		return (int)ret;
	}
};
