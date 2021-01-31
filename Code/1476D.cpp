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
    
    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        auto id = [&] (int x, int y) {
            return y * (n + 1) + x;
        };
    
        dsu dsu(n + n + 1 + 1);

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                dsu.Union(id(i + 1, 0), id(i, 1));
            } else {
                dsu.Union(id(i, 0), id(i + 1, 1));
            }
        }

        vector<int> sz(n + n + 1 + 1);
        for (int i = 0; i < n + n + 1 + 1; ++i) {
            sz[dsu.find(i)] ++;
        }

        for (int i = 0; i <= n; ++i) {
            cout << sz[dsu.find(i)] << " \n"[i == n];
        }
    }

    return 0;
}
