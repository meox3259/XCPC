#include <bits/stdc++.h>

using namespace std;

class dsu {
	private:
	vector<int> par;

	public:
	dsu(int N) : par(N) {
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void Union(int x, int y) {
		if(same(x, y)) {
			return;
		}

		x = find(x);
		y = find(y);
		par[x] = y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> len0(n + 1);
	vector<int> len1(n + 1);
	
	if(s[n - 1] == '?') {
		len0[n] = 1;
		len1[n] = 1;
	}

	if(s[n - 1] == '1') {
		len1[n] = 1;
	}

	if(s[n - 1] == '0') {
		len0[n] = 1;
	}

	for(int i = n - 2; i >= 0; --i) {
		if(s[i] == '0' || s[i] == '?') {
			len0[i + 1] = len0[i + 2] + 1;
		} 
		if(s[i] == '1' || s[i] == '?') {
			len1[i + 1] = len1[i + 2] + 1;
		}
	}

	vector<int> len(n + 1);
	for(int i = 1; i <= n; ++i) {
		len[i] = max(len0[i], len1[i]);
	}

	vector<vector<int> > p(n + 1);
	for(int i = 1; i <= n; ++i) {
		p[len[i]].emplace_back(i);	
	}

	vector<int> ans(n);
	dsu dsu(n + 2);

	for(int x = 1; x <= n; ++x) {
		int step = 0;
		for(int cur = dsu.find(1); cur <= n; cur = dsu.find(cur + x)) {
			step += 1;
		}	

		for(int i : p[x]) {
			dsu.Union(i, i + 1);
		}

		cout << step << " \n"[x == n];
	}

	return 0;
}
