#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 50;
const int H = maxn / 2 - 3;
const int inf = 1e9;
vector<int> G[maxn];
struct dsu {
	vector<int> fa;
	vector<int> cost;
	int sum = 0;
	void init() {
		fa.assign(maxn, 0);
		cost.assign(maxn, 0);
		for(int i = 0; i < maxn; ++i) {
			fa[i] = i;
			cost[i] = (i & 1) ^ 1;
		}
		cost[H << 1] = 0;
		cost[H << 1 | 1] = inf;
		sum = 0;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	void join(int x, int y, bool same) {
		int pos_x = find(x << 1), neg_x = find(x << 1 | 1);
		int pos_y = find(y << 1), neg_y = find(y << 1 | 1);
		if(same) {
			if(pos_x == pos_y) {
				return;
			}
			sum -= min(cost[pos_y], cost[neg_y]);
			sum -= min(cost[pos_x], cost[neg_x]);
			cost[pos_y] += cost[pos_x];
			cost[neg_y] += cost[neg_x];
			fa[pos_x] = pos_y;
			fa[neg_x] = neg_y;
		} else {
			if(pos_x == neg_y) {
				return;
			}
			sum -= min(cost[pos_y], cost[neg_y]);
			sum -= min(cost[pos_x], cost[neg_x]);
			cost[pos_y] += cost[neg_x];
			cost[neg_y] += cost[pos_x];
			fa[pos_x] = neg_y;
			fa[neg_x] = pos_y;
		}
		sum += min(cost[pos_y], cost[neg_y]);
	}
} dsu;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	string s;
	cin >> n >> k >> s;
	dsu.init();
	for(int i = 1; i <= k; ++i) {
		int c;
		cin >> c;
		while(c--) {
			int x;
			cin >> x;
			--x;
			G[x].emplace_back(i);
		}
	}
	for(int i = 0; i < n; ++i) {
		if(G[i].size() == 1) {
			dsu.join(G[i].back(), H, s[i] == '0');
		} else if(G[i].size() == 2) {
			dsu.join(G[i][0], G[i][1], s[i] == '1');
		}
		cout << dsu.sum << '\n';
	}
	return 0;
}
