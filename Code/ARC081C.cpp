#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();

	vector<vector<int> > p(26);
	for (int i = 0; i < n; ++i) {
		p[s[i] - 'a'].emplace_back(i);
	}

	for (int i = 0; i < 26; ++i) {
		p[i].emplace_back(n);
	}

	vector<vector<pair<int, int> > > G(n + 2);
	vector<int> deg(n + 2);
	int S = n + 1;
	int T = n;

	for (int i = 0; i < 26; ++i) {
		G[S].emplace_back(*p[i].begin(), i);
		deg[*p[i].begin()] ++;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			int nxt = *upper_bound(p[j].begin(), p[j].end(), i);
			G[i].emplace_back(nxt, j);
			deg[nxt] ++;
		}	
	}

	vector<int> d(n + 2, inf);
	vector<int> pre(n + 2);
	vector<vector<int> > rev(n + 2);
	queue<int> q;
	
	q.emplace(S);
	d[S] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto [y, c] : G[x]) {
			if ((-- deg[y]) == 0) {
				q.emplace(y);
			}
			d[y] = min(d[y], d[x] + 1);
		}
	}

	vector<int> rdeg(n + 2);
	for (int i = 0; i <= n + 1; ++i) {
		for (auto [j, c] : G[i]) {
			if (d[j] == d[i] + 1) {
				rev[j].emplace_back(i);
				rdeg[i] ++;
			}
		}
	}

	vector<int> db(n + 2, inf);

	for (int i = 0; i <= n + 1; ++i) {
		if (rdeg[i] == 0) {
			q.emplace(i);
		}
	}
	db[T] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int y : rev[x]) {
			if ((-- rdeg[y]) == 0) {
				q.emplace(y);
			}
			db[y] = min(db[y], db[x] + 1);
		}
	}

	int cur = S;
	while (cur != T) {
		sort(G[cur].begin(), G[cur].end(), [&] (auto x, auto y) {
			return x.second < y.second;
		});
		for (auto [nxt, c] : G[cur]) {
			if (d[cur] + db[nxt] + 1 == d[T]) {
				cur = nxt;
				cout << (char)(c + 'a');
				break;
			}
		}
	}

	cout << '\n';

	return 0;
}
