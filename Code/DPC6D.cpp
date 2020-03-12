#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn], d[maxn], used[maxn], ans[maxn];
set<int> s;
set<pair<int, int> > e;
vector<int> b;
void dfs(int p, int ban) {
	if(p == n + 1) {
		for(int i = 1; i <= n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}
	for(int i = 0; i < b.size(); ++i) {
		if(!used[b[i]] && b[i] != ban) {
			used[b[i]] = 1;
			ans[p] = b[i];
			dfs(p + 1, a[b[i]]);
			used[b[i]] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++d[a[i]];
	}
	for(int i = 1; i <= n; ++i) {
		s.emplace(i);
	}
	for(int i = 1; i <= n; ++i) {
		e.emplace(-d[i], i);
	}
	int ban = 0;
	for(int i = 1; i <= n - 5; ++i) {
		int u;
		if(-e.begin() -> first == n - i) {
			u = e.begin() -> second;
		} else if(*s.begin() != ban) {
			u = *s.begin();
		} else {
			u = *next(s.begin());
		}
		s.erase(u);
		e.erase({-d[u], u});
		used[u] = 1;
		if(!used[a[u]]) {
			e.erase({-d[a[u]], a[u]});
			--d[a[u]];
			e.emplace(-d[a[u]], a[u]);
		}
		ban = a[u];
		ans[i] = u;
	}
	b.assign(s.begin(), s.end());
	dfs(max(1, n - 4), ban);
	cout << -1 << '\n';
	return 0;
}
