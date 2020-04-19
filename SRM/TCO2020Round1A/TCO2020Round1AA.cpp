#include <bits/stdc++.h>

using namespace std;

class AveragePrice {
	public:
	double nonDuplicatedAverage(vector<int> prices) {
		sort(prices.begin(), prices.end());
		prices.erase(unique(prices.begin(), prices.end()), prices.end());

		double ret = 0;

		for(int i : prices) {
			ret += i;
		}

		return ret / (double)prices.size();
	}
};
