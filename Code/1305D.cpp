#include <bits/stdc++.h>
using namespace std;
int d[100005];
int main() {
	int n;
	cin >> n;
	vector<vector<int> > G;
	G.resize(n + 1);
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		++d[u];
		++d[v];
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(d[i] == 1) {
			q.emplace(i);
		}
	}
	auto ask = [&] (int u, int v) {
		cout << '?' << ' ' << u << ' ' << v << '\n';
		int w;
		cin >> w;
		return w;
	};
	while(q.size() > 1) {
		int u = q.front();
		q.pop();
		int v = q.front();
		q.pop();
		int w = ask(u, v);
		if(w == u) {
			cout << '!' << ' ' << u << '\n';
			return 0;
		}
		if(w == v) {
			cout << '!' << ' ' << v << '\n';
			return 0;
		}
		for(auto t : G[u]) {
			--d[t];
			if(d[t] == 1) {
				q.emplace(t);
			}
		}
		for(auto t : G[v]) {
			--d[t];
			if(d[t] == 1) {
				q.emplace(t);
			}
		}
	}
	cout << '!' << ' ' << q.front() << '\n';
	return 0;
}
