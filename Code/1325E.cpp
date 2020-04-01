#include <bits/stdc++.h>

using namespace std;

const int N = 1000000 + 5;
const int inf = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a;
	a.resize(n);

	vector<vector<int> > G;
	G.resize(N);

	vector<int> p = {1};

	vector<bool> isp;
	isp.resize(N);

	for(int i = 2; i < 1001; ++i) {
		if(!isp[i]) {
			p.emplace_back(i);
		}

		for(int j = i; j < 1001; j += i) {
			isp[j] = true;
		}
	}

	map<pair<int, int>, int> mp;

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		vector<int> pri;

		for(int j = 1; j < p.size(); ++j) {
			int c = 0;

			while(x % p[j] == 0) {
				x /= p[j];
				c ^= 1;
			}

			if(c == 1) {
				pri.emplace_back(p[j]);
			}
		}

		if(x > 1) {
			pri.emplace_back(x);
		}

		if(pri.empty()) {
			cout << 1 << '\n';
			return 0;
		} else {
			if(pri.size() == 1) {
				pri.emplace_back(1);
			}

			++mp[minmax(pri[0], pri[1])];

			G[pri[0]].emplace_back(pri[1]);
			G[pri[1]].emplace_back(pri[0]);
		}
	}

	for(auto& p : mp) {
		if(p.second > 1) {
			cout << 2 << '\n';
			return 0;
		}
	}

	int m = p.size();
	int ans = inf;

	for(int i = 0; i < m; ++i) {
		int s = p[i];

		queue<pair<int, int> > q;

		vector<int> d;
		d.resize(N, inf);
	
		d[s] = 0;
		q.emplace(s, -1);

		while(!q.empty()) {
			auto [u, f] = q.front();
			q.pop();

			for(auto v : G[u]) {
				if(v != f) {
					if(d[v] != inf) {
						ans = min(ans, d[u] + d[v] + 1);
					} else {
						d[v] = d[u] + 1;
						q.emplace(v, u);
					}
				}
			}
		}
	}

	if(ans == inf) {
		cout << -1 << '\n';
	} else {
		if(ans == 1) {
			cout << "ffff" << '\n';
		}

		cout << ans << '\n';
	}

	return 0;
}
