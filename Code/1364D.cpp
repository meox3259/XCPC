#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int> > G(n);

	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}

	vector<int> dep(n, -1);
	vector<bool> instack(n);

	int sz = n;

	function<void(int, int)> dfs = [&] (int u, int f) {
		instack[u] = true;
		for(int v : G[u]) {
			if(v != f) {
				if(dep[v] != -1) {
					if(instack[v]) {
						sz = min(sz, dep[u] - dep[v] + 1);
					}
				} else {
					dep[v] = dep[u] + 1;
					dfs(v, u);
				}
			}
		}
		instack[u] = false;
	};

	dep[0] = 0;
	dfs(0, -1);

	vector<int> st;
	vector<bool> vis(n);

	function<void(int, int)> find = [&] (int u, int f) {
		st.emplace_back(u);
		vis[u] = true;
		for(int v : G[u]) {
			if(v != f) {
				if(dep[v] <= dep[u]) {
					if(dep[u] - dep[v] + 1 == sz) {
						vector<int> ans;
						int cur = -1;
						while(cur != v) {
							cur = st.back();
							ans.emplace_back(cur);
							st.pop_back();
						}
						if(sz <= k) {
							cout << 2 << '\n';
							cout << ans.size() << '\n';
							for(int i : ans) {
								cout << i + 1 << ' ';
							}
							cout << '\n';
						} else {
							cout << 1 << '\n';
							for(int i = 0; i < k; ++i) {
								if(i % 2 == 0) {
									cout << ans[i] + 1 << ' ';
								}
							}
							cout << '\n';
						}	
						exit(0);
					}
				} else if(!vis[v]) {
					find(v, u);
				}
			}
		}
		st.pop_back();
	};

	find(0, -1);

	if(m == n - 1) {
		int cnt = 0;
		for(int i : dep) {
			if(i % 2 == 0) {
				cnt += 1;
			}
		}
		vector<int> ans;
		if(cnt >= (k + 1) / 2) {
			for(int i = 0; i < n; ++i) {
				if(dep[i] % 2 == 0) {
					ans.emplace_back(i);
				}
			} 
		} else {
			for(int i = 0; i < n; ++i) {
				if(dep[i] % 2 == 1) {
					ans.emplace_back(i);
				}
			}
		}
		cout << 1 << '\n';
		for(int i = 0; i < (k + 1) / 2; ++i) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
