#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class AlmostFibonacciKnapsack {
	public:
		vector<int> getIndices(long long x) {
			vector<ll> a = {2, 3};
			while(a.back() <= x) {
				a.push_back(a.back() + a.rbegin()[1] - 1);
			}
			a.pop_back();
			vector<int> ret;
			for(int i = a.size() - 1; ~i; --i) {
				if(x >= a[i] && x - a[i] != 1) {
					x -= a[i];
					ret.push_back(i + 1);
				}
			}
			return ret;
		}
};
