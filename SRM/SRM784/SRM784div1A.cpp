#include <bits/stdc++.h>

using namespace std;

class ValueDivision {
	public:
	vector<int> getArray(vector<int> a) {
		int n = a.size();

		vector<vector<int> > v;
		
		vector<int> vec;

		for(int i : a) {
			for(int j = max(1, i - n); j <= i; ++j) {
				vec.emplace_back(j);
			}
		}

		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());

		int m = vec.size();
		v.resize(m);

		for(int i = 0; i < n; ++i) {
			int p = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
			v[p].emplace_back(i);
		}

		set<int> s;
		vector<int> ans;
		ans.resize(n);

		for(int i = m - 1; i >= 0; --i) {
			for(int j : v[i]) {
				s.emplace(j);
			}

			if(!s.empty()) {
				ans[*s.rbegin()] = vec[i];
				s.erase(*s.rbegin());
			}
		}

		for(int i : s) {
			ans[i] = vec[0];
		}

		return ans;
	}
};
