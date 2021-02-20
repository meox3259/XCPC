#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, m;
        cin >> n >> m;

        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<long long> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        vector<vector<int> > adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            x --;
            y --;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        bool ok = true;
        vector<long long> bad(n);
        vector<long long> sz(n);
        auto dfs = [&] (auto &&f, int x, int par) -> void {
            sz[x] = p[x];
            for (int y : adj[x]) {
                if (y != par) {
                    f(f, y, x);
                    sz[x] += sz[y];
                }
            }
        };

        dfs(dfs, 0, -1);

        for (int i = 0; i < n; ++i) {
            bad[i] = (sz[i] - h[i]) / 2;
            if ((sz[i] - h[i]) % 2 == 1 || bad[i] < 0) {
                ok = false;
            }
        }

        auto check = [&] (auto &&f, int x, int par) -> void {
            long long sum = 0;
            for (int y : adj[x]) {
                if (y != par) {
                    f(f, y, x);
                    sum += bad[y];
                }
            }
            if (bad[x] - sum > p[x]) {
                ok = false;
            }
        };

        check(check, 0, -1);

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
