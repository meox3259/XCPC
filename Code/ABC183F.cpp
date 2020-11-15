#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

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

int cnt;
int lc[N * 60];
int rc[N * 60];
int sum[N * 60];

void update(int l, int r, int &x, int p, int v) {
	x = ++cnt;
	sum[x] += v;
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		update(l, mid, lc[x], p, v);
	} else {
		update(mid + 1, r, rc[x], p, v);
	}
}

int merge(int x, int y) {
	if(x == 0) {
		return y;
	}
	if(y == 0) {
		return x;
	}
	int z = ++cnt;
	sum[z] = sum[x] + sum[y];
	lc[z] = merge(lc[x], lc[y]);
	rc[z] = merge(rc[x], rc[y]);
	return z;
}

int query(int l, int r, int x, int p) {
	if(l == r) {
		return sum[x];
	}
	int mid = l + r >> 1;
	if(p <= mid) {
		return query(l, mid, lc[x], p);
	} else {
		return query(mid + 1, r, rc[x], p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> c(n);
	for(int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	vector<int> root(n);

	for(int i = 0; i < n; ++i) {
		c[i] -= 1;
	}

	for(int i = 0; i < n; ++i) {
		update(0, n - 1, root[i], c[i], 1);
	}

	dsu dsu(n);

	while(q--) {
		int opt, x, y;
		cin >> opt >> x >> y;
		--x; --y;

		if(opt == 1) {
			if(!dsu.same(x, y)) {
				x = dsu.find(x);
				y = dsu.find(y);
				root[x] = merge(root[x], root[y]);
				dsu.Union(y, x);
			}
		}

		if(opt == 2) {
			cout << query(0, n - 1, root[dsu.find(x)], y) << '\n';	
		}
	}

	return 0;
}
