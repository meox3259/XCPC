#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

struct dsu {
    int a, b, fa, sizea, sizeb, da, db;
    vector<int> dd;
    dsu(int a = 0, int b = 0, int fa = 0, int sizea = 0, int sizeb = 0, int da = 0, int db = 0) : a(a), b(b), fa(fa), sizea(sizea), sizeb(sizeb) {}
} st[N * 2];
int n, m, top, T;
int d[N], fa[N], Size[N];
bool unite(pair<int, int> o)
{
    int u = o.first, v = o.second, du = 0, dv = 0;
    while(fa[u] != u)
    {
        du ^= d[u];
        u = fa[u];
    }
    while(fa[v] != v)
    {
        dv ^= d[v];
        v = fa[v];
    }
    if(Size[u] < Size[v]) swap(u, v);
    st[++top] = dsu(u, v, fa[v], Size[u], Size[v], d[u], d[v]);
    if(u == v)
    {
        if(du == dv) return false;
        return true;
    }
    Size[u] += Size[v];
    d[v] = du ^ dv ^ 1;
    fa[v] = u;
    return true;
}
void del(int now)
{
    while(top != now)
    {
        dsu x = st[top];
        Size[x.a] = x.sizea;
        Size[x.b] = x.sizeb;
        d[x.a] = x.da;
        d[x.b] = x.db;
        fa[x.b] = x.fa;
        --top;
    }
}

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

    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        Size[i] = 1;
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
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (c[i] == c[j]) {
                if (!unite(make_pair(i, j))) {
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
        int now = top;
        for (auto [x, y] : vec) {
            if (!unite(make_pair(x, y))) {
                ok = false;
            }
        }
        del(now);
        if (!ok) {
            ans --;
        }
    }

    cout << ans << '\n';

    return 0;
}
