#include <bits/stdc++.h>
using namespace std;
class ANewHope {
	public:
	int count(vector <int> a, vector <int> b, int D) {
		int n = a.size(), ans = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(a[i] == b[j]) {
					ans = max(ans, (i - j + n - D - 1) / (n - D) + 1);
				}
			}
		}		
		return ans;
	}
};
