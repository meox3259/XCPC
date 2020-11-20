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

	int n, m;
	cin >> n >> m;

	vector<int> t(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	for(int i = 0; i < n; ++i) {
		t[i] -= 1;
	}

	vector<set<int> > s(m);
	for(int i = 0; i < n; ++i) {
		s[t[i]].emplace(i);
	}

	for(int i = 0; i < m; ++i) {
		s[i].emplace(-1);
	}

	dsu dsu(m);

	int ans = 0;

	for(int i = 0; i < m; ++i) {
		vector<int> tmp;
		for(int j : s[i]) {
			tmp.emplace_back(j);
		}	
		for(int j = 0; j + 1 < tmp.size(); ++j) {
			ans += (tmp[j] + 1 != tmp[j + 1]);
		}
	}	

	cout << ans << '\n';

	for(int _ = 0; _ < m - 1; ++_) {
		int a, b;
		cin >> a >> b;
		--a; --b;

		a = dsu.find(a);
		b = dsu.find(b);

		if(s[a].size() > s[b].size()) {
			swap(a, b);
		}

		dsu.Union(a, b);

		vector<int> tmp;
		for(int i : s[a]) {
			tmp.emplace_back(i);
		}

		for(int i = 0; i + 1 < tmp.size(); ++i) {
			ans -= (tmp[i] + 1 != tmp[i + 1]);
		}

		for(int i : s[a]) {
			if(i != -1) {
				s[b].emplace(i);
				auto it = s[b].find(i);
				if(next(it) != s[b].end()) {
					ans -= (*next(it) != *prev(it) + 1);	
					ans += (i + 1 != *next(it));
				}
				ans += (*prev(it) + 1 != i);
			}
		}

		s[a].clear();

		cout << ans << '\n';
	}

	return 0;
}
