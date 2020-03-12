#include <bits/stdc++.h>
using namespace std;
class SmilesTheFriendshipUnicorn {
	public:
		string hasFriendshipChain(int n, vector <int> a, vector <int> b) {
			int m = a.size();
			vector<vector<int> > G(n + 5);
			vector<vector<bool> > mp(n + 5, vector<bool>(n + 5, 0));
			for(int i = 0; i < m; ++i) {
				G[a[i]].push_back(b[i]);
				G[b[i]].push_back(a[i]);
				mp[a[i]][b[i]] = mp[b[i]][a[i]] = 1;
			}
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < G[i].size(); ++j) {
					for(int k = j + 1; k < G[i].size(); ++k) {
						int t = 0;
						int x = G[i][j], y = G[i][k];
						if(G[x].size() > 2 || (G[x].size() == 2 && mp[x][y] == 0)) {
							++t;
						}
						if(G[y].size() > 2 || (G[y].size() == 2 && mp[x][y] == 0)) {
							++t;
						}
						if(t == 2) {
							return "Yay!";
						}
					}
				}
			}
			return ":(";
		}
}; 
