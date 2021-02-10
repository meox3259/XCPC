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

    vector<vector<int> > adj(n);
    vector<pair<int, int> > edge;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        edge.emplace_back(x, y);
        mp[minmax(x, y)] = i;
    }

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    dsu dsu(n);
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (c[i] == c[j]) {
                dsu.Union(i, j);
            }
        }
    }

    vector<int> ans(m);
    for (auto [x, y] : edge) {
        if (!dsu.same(x, y)) {
            if (c[dsu.find(x)] > c[dsu.find(y)]) {
                ans[mp[minmax(x, y)]] = 1;
            } else {
                ans[mp[minmax(x, y)]] = -1;
            }
        }
    }

    vector<bool> vis(n);
    auto dfs = [&] (auto &&f, int x) -> void {
        vis[x] = true;
        for (int y : adj[x]) {
            if (c[x] == c[y]) {
                int i = mp[minmax(x, y)];
                if (ans[i] == 0) {
                    ans[i] = (edge[i] == make_pair(x, y) ? 1 : -1);
                }
                if (!vis[y]) {
                    f(f, y);
                } 
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << (ans[i] == 1 ? "->" : "<-") << '\n';
    }

    return 0;
}
