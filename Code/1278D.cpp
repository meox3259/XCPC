#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
int mir[maxn * 2], vis[maxn];
vector<pair<int, int> > v;
set<int> s;
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
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		v.push_back(make_pair(l, r));
		mir[r] = i;
	}
	int cnt = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i) {
		if(cnt == n) {
			break;
		}
		pair<int, int> o = v[i];
		int l = o.first, r = o.second;
		for(auto it = s.lower_bound(l); it != s.end(); ++it) {
			if(*it > r) {
				break;
			}
			G[mir[r]].push_back(mir[*it]);
			G[mir[*it]].push_back(mir[r]);
			++cnt;
			if(cnt == n) {
				break;
			}
		}
		s.insert(r);
	}
	if(cnt != n - 1) {
		puts("NO");
		return 0;
	}
	dfs(1);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
