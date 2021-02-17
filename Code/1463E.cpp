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

    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] --;
    }

    vector<int> nxt(n, -1);
    vector<vector<int> > adj(n);
    vector<int> in(n);
    vector<int> deg(n);
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
        x[i] --;
        y[i] --;
        adj[x[i]].emplace_back(y[i]);
        in[y[i]] ++;
        nxt[x[i]] = y[i];
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            adj[p[i]].emplace_back(i);
            in[i] ++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }

    int tot = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        tot ++;
        for (int y : adj[x]) {
            if (! --in[y]) {
                q.emplace(y);
            }
        }
    }

    if (tot != n) {
        cout << 0 << '\n';
        exit(0);
    }

    dsu dsu(n);
    for (int i = 0; i < k; ++i) {
        if (dsu.same(x[i], y[i])) {
            cout << 0 << '\n';
            exit(0);
        } else {
            dsu.Union(x[i], y[i]);
            deg[y[i]] ++;
        }
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1 && !dsu.same(i, p[i])) {
            in[dsu.find(i)] ++;
            g[dsu.find(p[i])].emplace_back(dsu.find(i));
        }
    }

    for (int i = 0; i < k; ++i) {
        if (!dsu.same(x[i], y[i])) {
            in[dsu.find(y[i])] ++;
            g[dsu.find(x[i])].emplace_back(dsu.find(y[i]));
        }
    }

    tot = 0;
    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            tot ++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i && !in[i]) {
            q.emplace(i);
        }
    }

    vector<int> node;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        node.emplace_back(x);
        for (int y : g[x]) {
            if (! --in[y]) {
                q.emplace(y);
            }
        }
    }
    
    if (node.size() != tot) {
        cout << 0 << '\n';
        exit(0);
    }

    vector<vector<int> > hav(n);
    for (int i = 0; i < n; ++i) {
        hav[dsu.find(i)].emplace_back(i);
    }

    vector<int> ans;
    for (int i : node) {
        if (!hav[i].empty()) {
            for (int j : hav[i]) {
                if (deg[j] == 0) {
                    while (j != -1) {
                        ans.emplace_back(j);
                        j = nxt[j];
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
