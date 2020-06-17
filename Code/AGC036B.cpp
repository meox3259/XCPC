#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long k;
	cin >> n >> k;

	vector<int> a(n * 2);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i < n; ++i) {
		a[i + n] = a[i];
	}

	map<int, int> pos;
	vector<int> nxt(n * 2 + 1, -1);
	vector<int> pre(n * 2 + 1, -1);
	for(int i = n * 2 - 1; i >= 0; --i) {
		if(pos.count(a[i])) {
			nxt[i] = pos[a[i]] + 1;
			pre[pos[a[i]] + 1] = i;
			pos[a[i]] = i;
		} else {
			nxt[i] = -1;
			pos[a[i]] = i;
		}
	} 

	vector<int> to(n * 2 + 1, -1);
	function<void(int)> dfs = [&] (int cur) {
		if(nxt[cur] == -1) {
			to[cur] = cur - n;
			return;
		}
		if(to[cur] != -1) {
			return;
		}
		dfs(nxt[cur]);
		to[cur] = to[nxt[cur]];
	};

	for(int i = 0; i < n; ++i) {
		dfs(i);
	}
	
	to[n] = 0;

	vector<vector<int> > jump(n + 1, vector<int> (62, -1));
	for(int i = 0; i <= n; ++i) {
		jump[i][0] = to[i];}

	for(int j = 0; j < 61; ++j) {
		for(int i = 0; i <= n; ++i) {
			jump[i][j + 1] = jump[jump[i][j]][j];
		}
	}

	int cur = 0;

	k -= 1;

	for(int i = 62; i >= 0; --i) {
		if(k >> i & 1) {
			cur = jump[cur][i];
		}
	}

	vector<int> ans;
	map<int, bool> vis;
	for(int i = cur; i < n; ++i) {
		if(vis[a[i]]) {
			while(ans.back() != a[i]) {
				vis[ans.back()] = false;
				ans.pop_back();
			}
			ans.pop_back();
			vis[a[i]] = false;
		} else {
			vis[a[i]] = true;
			ans.emplace_back(a[i]);
		}
	}

	for(int i : ans) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
