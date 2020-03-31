#include <bits/stdc++.h>

using namespace std;

class dsu {
	vector<int> par;

	public:
	dsu(int n) {
		par.resize(n);
		for(int i = 0; i < n; ++i) {
			par[i] = i;
		}
	}

	int find(int x) {
		return x == par[x] ? x : par[x] = find(par[x]);
	}

	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if(x == y) {
			return;
		}

		par[x] = y;
	}

	int solve(string s) {
		vector<vector<int> > cnt;
		cnt.resize(par.size());

		for(int i = 0; i < par.size(); ++i) {
			cnt[i].resize(26);
		}

		for(int i = 0; i < par.size(); ++i) {
			++cnt[find(i)][s[i] - 'a'];	
		}

		int ans = par.size();

		for(int i = 0; i < par.size(); ++i) {
			if(par[i] == i) {
				ans -= *max_element(cnt[i].begin(), cnt[i].end());
			}
		}

		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;

	while(T--) {
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;
		
		dsu dsu(n);

		for(int i = 0; i < n; ++i) {
			dsu.merge(i, n - i - 1);
		}

		for(int i = 0; i < k; ++i) {
			for(int j = i; j < n; j += k) {
				dsu.merge(i, j);
			}
		}

		cout << dsu.solve(s) << '\n';
	}

	return 0;
}
