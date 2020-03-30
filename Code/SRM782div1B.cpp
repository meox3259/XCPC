#include <bits/stdc++.h>

using namespace std;

class RankingStudents {
	public:
		string rankingPossible(int n, vector <int> f, vector <int> a, vector <int> b) {
			int m = a.size();
			priority_queue<pair<int, int> > q;

			vector<vector<int> > G;
			G.resize(n);

			vector<int> d;
			d.resize(n);

			for(int i = 0; i < m; ++i) {
				G[b[i]].emplace_back(a[i]);
				++d[a[i]];
			}

			for(int i = 0; i < n; ++i) {
				if(d[i] == 0) {
					q.emplace(f[i], i);
				}
			}

			int cnt = n;
			
			while(!q.empty()) {
				auto o = q.top();
				q.pop();

				int u = o.second;

				if(--cnt > o.first) {
					return "Impossible";
				}

				for(auto v : G[u]) {
					if(!--d[v]) {
						q.emplace(f[v], v);
					}
				}
			}

			if(cnt == 0) {
				return "Possible";
			} else {
				return "Impossible";
			}
		}
};
