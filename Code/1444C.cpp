#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

class rollbackdsu {
    private:
    vector<int> par;
    vector<int> sz;
    vector<int> d;
    vector<tuple<int, int, int, int, int, int> > hist;
    public:
    rollbackdsu(int n) : par(n), sz(n, 1), d(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        while (x != par[x]) {
            x = par[x];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool Union(int x, int y) {
        int dx = 0;
        while (par[x] != x) {
            dx ^= d[x];
            x = par[x];
        }
        int dy = 0;
        while (par[y] != y) {
            dy ^= d[y];
            y = par[y];
        }
        if (x == y) {
            return dx != dy;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        hist.emplace_back(x, y, sz[x], sz[y], d[x], d[y]);
        sz[x] += sz[y];
        d[y] = dx ^ dy ^ 1;
        par[y] = x;
        return true;
    }
    void clear() {
        hist.clear();
    }
    void rollback() {
        while (!hist.empty()) {
            int x = get<0> (hist.back());
            int y = get<1> (hist.back());
            sz[x] = get<2> (hist.back());
            sz[y] = get<3> (hist.back());
            d[x] = get<4> (hist.back());
            d[y] = get<5> (hist.back());
            par[y] = y;
            hist.pop_back();
        } 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        c[i] --;
    }

    vector<vector<int> > adj(n);
    vector<vector<int> > same(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<bool> ban(k);
    rollbackdsu dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (c[i] == c[j]) {
                if (!dsu.Union(i, j)) {
                    ban[c[i]] = true;
                }
            }
        }
    }

    long long ans = 1LL * k * (k - 1) / 2;
    long long tot = 0;
    for (int i = 0; i < k; ++i) {
        if (ban[i]) {
            tot ++;
        }
    }

    ans -= tot * (tot - 1) / 2;
    ans -= tot * (k - tot);

    map<pair<int, int>, vector<pair<int, int> > > edge;

    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (c[i] != c[j] && !ban[c[i]] && !ban[c[j]]) {
                edge[minmax(c[i], c[j])].emplace_back(i, j);
            }
        }
    }

    for (auto &o : edge) {
        auto &vec = o.second;
        bool ok = true; 
        dsu.clear();
        for (auto [x, y] : vec) {
            if (!dsu.Union(x, y)) {
                ok = false;
            }
        }
        dsu.rollback();
        if (!ok) {
            ans --;
        }
    }

    cout << ans << '\n';

    return 0;
}
