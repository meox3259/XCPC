#include <bits/stdc++.h>
using namespace std;
class MultiplicationTable2 {
	public:
		int minimalGoodSet(vector <int> a) {
			int n = sqrt(a.size());
			vector<vector<int> > g(n, vector<int>(n));
			auto solve = [&](int x) {
				if(g[x][x] == x) return 1;
				vector<int> s;
				vector<bool> h(n);
				s.push_back(x);
				h[x] = 1;
				while(1) {
					bool flag = 1;
					vector<int> ns = s;
					for(int i = 0; i < s.size(); ++i) 
						for(int j = 0; j < s.size(); ++j) {
							int k = g[s[i]][s[j]];
							if(!h[k]) {
								h[k] = 1;
								ns.push_back(k);
								flag = 0;
							}
						}
					if(flag)
						break;
					s = ns;
				}
				return (int)s.size();
			};
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					g[i][j] = a[i * n + j];
			int ans = n;
			for(int i = 0; i < n; ++i) 
				ans = min(ans, solve(i));
			return ans;
		}
};
