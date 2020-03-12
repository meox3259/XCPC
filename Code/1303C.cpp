#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int> > G;
		if(n == 1) {
			cout << "YES" << '\n';
			for(int i = 0; i < 26; ++i) {
				cout << (char)('a' + i);
			}
			cout << '\n';
			continue;
		}
		G.resize(26);
		for(int i = 1; i < n; ++i) {
			int x = s[i - 1] - 'a', y = s[i] - 'a';
			G[x].emplace_back(y);
			G[y].emplace_back(x);
		}
		bool f = 1;
		for(int i = 0; i < 26; ++i) {
			sort(G[i].begin(), G[i].end());
			G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
		}
		for(int i = 0; i < 26; ++i) {
			if(G[i].size() > 2) {
				f = 0;
				break;
			}
		}
		if(!f) {
			cout << "NO" << '\n';
			continue;
		}
		int p = -1;
		for(int i = 0; i < 26; ++i) {
			if(G[i].size() == 1) {
				p = i;
				break;
			}
		}
		if(p == -1) {
			cout << "NO" << '\n';
			continue;
		}
		vector<int> ans;
		vector<int> vis;
		vis.assign(26, 0);
		for(int i = 0; i < n; ++i) {
			vis[s[i] - 'a'] = 1;
		}
		function<void(int, int)> dfs = [&] (int u, int f) {
			ans.emplace_back(u);
			for(auto v : G[u]) {
				if(v != f) {
					dfs(v, u);
				}
			}	
		};
		dfs(p, -1);
		for(int i = 0; i < 26; ++i)	{
			if(!vis[i]) {
				ans.emplace_back(i);
			}
		}
		if(ans.size() != 26) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for(int i = 0; i < ans.size(); ++i) {
			cout << (char)(ans[i] + 'a');
		}
		cout << '\n';
	}
	return 0;
}
