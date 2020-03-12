#include <bits/stdc++.h>
using namespace std;
const int maxn = 2505;
class FiringEmployees {
	public:
	vector<int> G[maxn];
	int val[maxn];
	int dfs(int u) {
		int ret = 0;
		if(u) {
			ret += val[u - 1];
		}
		for(auto v : G[u]) {
			ret += dfs(v);
		}
		return max(ret, 0);
	}
	int fire(vector <int> fa, vector <int> a, vector <int> b) {
		for(int i = 0; i < fa.size(); ++i) {
			G[fa[i]].push_back(i + 1);
			val[i] = b[i] - a[i];
		}
		return dfs(0);
	}
};
