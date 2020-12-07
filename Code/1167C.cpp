#include <bits/stdc++.h>

using namespace std;

class dsu {
    private:
    vector<int> par;
	vector<int> sz;

    public:
    dsu(int N) : par(N), sz(N) {
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
		sz[y] += sz[x];
    }

	void set(int x) {
		sz[x] = 1;
	}

	int get(int x) {
		return sz[x];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	dsu dsu(n + m);
	for (int i = 0; i < n; ++i) {
		dsu.set(i);
	}
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			x --;
			dsu.Union(x, i + n);
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << dsu.get(dsu.find(i)) << " \n"[i == n - 1];	
	}

	return 0;
}
