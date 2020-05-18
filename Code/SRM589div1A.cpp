#include <bits/stdc++.h>

using namespace std;

class dsu {
	vector<int> par;
	
	public:
	dsu(int N) : par(N) { 
		iota(par.begin(), par.end(), 0); 
	}

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	void Union(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) {
			return;
		}
		par[y] = x;
	}
};

class GooseTattarrattatDiv1 {
	public:
	int getmin(string S) {
		int n = S.size();
		dsu dsu(26);
		for(int i = 0; i < n; ++i) {
			int x = S[i] - 'a';
			int y = S[n - i - 1] - 'a';
			dsu.Union(x, y);
		}
		vector<int> cnt(26);
		for(char c : S) {
			++cnt[c - 'a'];
		}
		vector<vector<int> > tot(26);
		for(int i = 0; i < 26; ++i) {
			tot[dsu.find(i)].emplace_back(cnt[i]);
		}
		int ans = n;
		for(int i = 0; i < 26; ++i) {
			if(!tot[i].empty()) {
				ans -= *max_element(tot[i].begin(), tot[i].end());
			}
		}
		return ans;
	}
};
