#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<vector<int> > G(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(i - a[i] >= 1) {
			G[i - a[i]].push_back(i);
		}
		if(i + a[i] <= n) {
			G[i + a[i]].push_back(i);
		}
	}
	vector<int> d(n + 1, -1);
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(a[i] & 1) {
			d[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	vector<int> ans(n + 1);
	for(int i = 1; i <= n; ++i) {
		if(!(a[i] & 1)) {
			ans[i] = d[i];
		}
	}
	for(int i = 1; i <= n; ++i) {
		d[i] = -1;
	}
	for(int i = 1; i <= n; ++i) {
		if(!(a[i] & 1)) {
			q.push(i);
			d[i] = 0;
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v : G[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(a[i] & 1) {
			ans[i] = d[i];
		}
	}
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
