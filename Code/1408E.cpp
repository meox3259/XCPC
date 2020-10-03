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

	int m, n;
	cin >> m >> n;

	vector<int> a(m);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	vector<int> s(m);

	dsu dsu(n + m);

	vector<tuple<int, int, int> > edge;
	long long ans = 0;
	for(int i = 0; i < m; ++i) {
		cin >> s[i];
		for(int j = 0; j < s[i]; ++j) {
			int x;
			cin >> x;
			--x;
			edge.emplace_back(a[i] + b[x], i, x + m);	
			ans += a[i] + b[x];
		}
	}

	sort(edge.begin(), edge.end(), greater<tuple<int, int, int> > ());

	for(auto [w, x, y] : edge) {
		if(!dsu.same(x, y)) {
			ans -= w;
			dsu.Union(x, y);
		}
	}

	cout << ans << '\n';

	return 0;
}
