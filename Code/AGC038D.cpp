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

    int n, q;
    long long m;
    cin >> n >> m >> q;

    vector<int> a(q);
    vector<int> b(q);
    vector<int> c(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    dsu dsu(n);
    long long tot = 0;
    for (int i = 0; i < q; ++i) {
        if (c[i] == 0) {
            dsu.Union(a[i], b[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dsu.find(i) == i) {
            tot ++;
        }
    }

    long long low = n;
    long long high = tot * (tot - 1) / 2 + n - tot;

    bool ok = true;
    bool cir = false;
    for (int i = 0; i < q; ++i) {
        if (c[i] == 1) {
            if (dsu.same(a[i], b[i])) {
                ok = false;
            }
            cir = true;
        } 
    }

    if (cir) {
        low = n;
        if (tot < 2 || m < low || m > high) {
            ok = false;
        }
    } else {
        low = n - 1;
        if (m < low || m > high) {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}
