#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	vector<vector<int> > G(n);

	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	vector<int> col(n, -1);
	vector<vector<vector<int> > > node;
	vector<int> zero;
	vector<int> one;

	function<void(int, int)> dfs = [&] (int u, int cur) {
		col[u] = cur;
		if(cur == 0) {
			zero.emplace_back(u);
		} else {
			one.emplace_back(u);
		}
		for(int v : G[u]) {
			if(col[v] == -1) {
				dfs(v, cur ^ 1);
			} else if(col[v] == cur) {
				cout << "NO" << '\n';
				exit(0);
			}
		}
	};

	for(int i = 0; i < n; ++i) {
		if(col[i] == -1) {
			zero.clear();
			one.clear();
			dfs(i, 0);
			node.push_back({ zero, one });
		}
	}

	int r = node.size();

	vector<vector<int> > dp(r + 1, vector<int> (n2 + 1, 0));
	dp[0][0] = 1;
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k + node[i][j].size() <= n2; ++k) {
				dp[i + 1][k + node[i][j].size()] |= dp[i][k];
			}
		}
	}

	if(!dp[r][n2]) {
		cout << "NO" << '\n';
		exit(0);
	}

	string ans(n, ' ');
	int cur = n2;

	for(int i = r - 1; i >= 0; --i) {
		for(int j = 0; j < 2; ++j) {
			if(cur >= node[i][j].size() && dp[i][cur - node[i][j].size()]) {
				cur -= node[i][j].size();
				for(int k : node[i][j]) {
					ans[k] = '2';
				}
				for(int k : node[i][j ^ 1]) {
					if(n1 > 0) {
						n1 -= 1;
						ans[k] = '1';
					} else {
						ans[k] = '3';
					}
				}
				break;
			}
		}
	}

	cout << "YES" << '\n';
	cout << ans << '\n';

	return 0;
}
