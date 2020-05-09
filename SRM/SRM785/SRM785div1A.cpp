#include <bits/stdc++.h>

using namespace std;

void chkmin(int &x, int y) {
	if(x > y) {
		x = y;
	}
}

class EllysPalMul {
	public:
	int getMin(int X) {
		int m = 10000000;

		vector<long long> fac(20);
		fac[0] = 1;
		for(int i = 0; i < 19; ++i) {
			fac[i + 1] = fac[i] * 10; 
		}

		int ret = 1000000001;
		int lim = 1000000000;
		bool ok = false;

		for(int i = 1; i <= m; ++i) {
			int num = i;
			vector<int> st;
			while(num) {
				st.emplace_back(num % 10);
				num /= 10;
			}
			reverse(st.begin(), st.end());
			int k = st.size();
			long long t = 0;
			for(int j = 0; j < k; ++j) {
				t += fac[j] * st[j];
			}
			long long cur = fac[k] * i + t;
			if(cur % X == 0 && cur / X <= lim) {
				ret = min(ret, cur / X);
				ok = true;
			}
			t -= fac[k - 1] * st.back();
			cur = fac[k - 1] * i + t;
			if(cur % X == 0) {
				ret = min(ret, cur / X);
				ok = true;
			}
		}

		if(!ok) {
			return -1;
		} else {
			return ret;
		}
	}
};
