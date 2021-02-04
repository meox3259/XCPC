#include <bits/stdc++.h>

using namespace std;

class LowestCommonAncestor {
    const int LOG = 20;
    vector<int> d;
    vector<vector<int> > jump;
    public:
    LowestCommonAncestor(vector<vector<int> > adj, int Root) {
        int N = adj.size();
        d = vector<int> (N, -1);
        d[Root] = 0;
        queue<int> q;
        q.push(Root);
        vector<int> p(N, -1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    p[y] = x;
                    q.push(y);
                }
            }
        }   
        jump = vector<vector<int> > (LOG, vector<int> (N, -1));
        for (int i = 0; i < N; ++i) {
            jump[0][i] = p[i];
        }
        for (int i = 1; i < LOG; ++i) {
            for (int j = 0; j < N; ++j) {
                if (jump[i - 1][j] != -1) {
                    jump[i][j] = jump[i - 1][jump[i - 1][j]];
                }
            }
        }
    }
    int up(int x, int d) {
        for (int i = 0; i < LOG; ++i) {
            if (d >> i & 1){
                x = jump[i][x];
            }
        }
        return x;
    }
    int lca(int x, int y) {
        if (d[x] > d[y]) {
            swap(x, y);
        }
        y = up(y, d[y] - d[x]);
        if (x == y) {
            return x;
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (jump[i][x] != jump[i][y]) {
                x = jump[i][x];
                y = jump[i][y];
            }
        }
        return jump[0][x];
    }
};

class SegmentTree {
    vector<int> sum;
    vector<int> sz;
    vector<int> lc;
    vector<int> rc;
    int Pool;

    public:
    SegmentTree() {}
    SegmentTree(int n) : sum(n * 60), lc(n * 60), rc(n * 60), sz(n * 60) { 
        Pool = 0;
    }

    void update(int l, int r, int &x, int last, int p, int v) {
        x = ++Pool;
        sz[x] = sz[last] + 1;
        sum[x] = sum[last] + v;
        lc[x] = lc[last];
        rc[x] = rc[last];
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid) {
            update(l, mid, lc[x], lc[last], p, v);
        } else {
            update(mid + 1, r, rc[x], rc[last], p, v);
        }
    }

    int QuerySum(int l, int r, int x, int a, int b) {
        if (l > b || r < a || x == 0) {
            return 0;
        }
        if (l >= a && r <= b) {
            return sum[x];
        }
        int mid = l + r >> 1;
        return QuerySum(l, mid, lc[x], a, b) + QuerySum(mid + 1, r, rc[x], a, b);
    }

    int QuerySize(int l, int r, int x, int a, int b) {
        if (l > b || r < a || x == 0) {
            return 0;
        }
        if (l >= a && r <= b) {
            return sz[x];
        }
        int mid = l + r >> 1;
        return QuerySize(l, mid, lc[x], a, b) + QuerySize(mid + 1, r, rc[x], a, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<tuple<int, int, int> > > adj(n);
    vector<vector<int> > to(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a --;
        b --;
        adj[a].emplace_back(b, c, d);
        adj[b].emplace_back(a, c, d);
        to[a].emplace_back(b);
        to[b].emplace_back(a);
    }

    LowestCommonAncestor LCA(to, 0);

    SegmentTree seg(n);
    vector<long long> dis(n);
    vector<int> root(n);
    auto dfs = [&] (auto &&f, int x, int par) -> void {
        for (auto [y, c, d] : adj[x]) {
            if (y != par) {
                dis[y] = dis[x] + d;
                seg.update(0, n - 1, root[y], root[x], c, d);
                f(f, y, x); 
            }
        }
    };

    dfs(dfs, 0, -1);

    while (q --) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        u --;
        v --;
        int w = LCA.lca(u, v);
        int cnt = seg.QuerySize(0, n - 1, root[u], x, x) + seg.QuerySize(0, n - 1, root[v], x, x) - 2 * seg.QuerySize(0, n - 1, root[w], x, x);
        int sum = dis[u] + dis[v] - 2 * dis[w];
        int delta = seg.QuerySum(0, n - 1, root[u], x, x) + seg.QuerySum(0, n - 1, root[v], x, x) - 2 * seg.QuerySum(0, n - 1, root[w], x, x);
        cout << sum - delta + cnt * y << '\n';
    }

    return 0;
}
