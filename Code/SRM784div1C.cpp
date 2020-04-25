#include <bits/stdc++.h>

using namespace std;

class TAASquares {
	public:
	vector<string> construct(int n) {
		vector<string> ans;
		ans.resize(n);

		for(int i = 0; i < n; ++i) {
			ans[i].assign(n, '0');
		}

		for(int i = 0; i < n; ++i) {
			for(int j = i; j < n; ++j) {
				ans[i][j] = '2';
			}
		}

		for(int i = 0; i < n / 2; ++i) {
			ans[i][i] = '1';
		}

		return ans;
	}
};
