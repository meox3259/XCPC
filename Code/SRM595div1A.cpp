#include <bits/stdc++.h>

using namespace std;

class LittleElephantAndIntervalsDiv1 {
	public:
	long long getNumber(int M, vector <int> L, vector <int> R) {
		int n = L.size();
		
		long long ret = 1;

		vector<bool> vis;
		vis.resize(n);

		vector<int> c;
		c.resize(M, -1);

		for(int i = 0; i < n; ++i) {
			for(int j = L[i] - 1; j < R[i]; ++j) {
				c[j] = i;
			}
		}

		for(int i = 0; i < M; ++i) {
			if(c[i] != -1) {
				vis[c[i]] = true;
			}
		}

		for(bool f : vis) {
			if(f) {
				ret = ret * 2;
			}
		}

		return ret;
	}
};
