#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a --;
        b --;

        vector<vector<int> > adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            x --;
            y --;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        if (da + da >= db) {
            cout << "Alice" << '\n';
            continue;
        }

        vector<int> dp(n);
        vector<int> dep(n);
        int Max = 0;
        auto dfs = [&] (auto &&f, int x, int par) -> void {
            for (int y : adj[x]) {
                if (y != par) {
                    dep[y] = dep[x] + 1;
                    f(f, y, x);
                    Max = max(Max, dp[x] + dp[y] + 1);
                    dp[x] = max(dp[x], dp[y] + 1);
                }
            }  
        };

        dfs(dfs, a, -1);

        if (dep[b] > da && Max > da + da) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }

    return 0;
}
