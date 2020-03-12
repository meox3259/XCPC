#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int vis[maxn];
vector<int> G[maxn];
void dfs(int u) {
	if(vis[u]) {
		return;
	}
	vis[u] = 1;
	for(auto v : G[u]) {
		dfs(v);
	}
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			vis[i] = 0;
			G[i].clear();
			e[i]
		}
		map<pair<int, int>, vector<int> > mp;
		for(int i = 1; i <= n; ++i) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			if(a > b) {
				swap(a, b);
			}
			if(b > c) {
				swap(b, c);
			}
			if(a > b) {
				swap(a, b);
			}
			e[a] ^= b; 
			e[a] ^= c;
			e[b] ^= a;
			e[b] ^= c;
			e[c] ^= a;
			e[c] ^= b;
			mp[make_pair(a, b)].push_back(i);
			mp[make_pair(b, c)].push_back(i);
			mp[make_pair(a, c)].push_back(i);
		}
		int x, y;
		for(auto t : mp) {
			if(t.second.size() == 1) {
				x = t.second
			}
		}
	}
	return 0;
}
