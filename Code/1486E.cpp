#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > dp(n, vector<int> (51, inf));
    vector<vector<pair<int, int> > > adj(n);
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u --;
        v --;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > q; 
    q.emplace(0, 0, 0);

    while (!q.empty()) {
        auto [cur, x, i] = q.top();
        q.pop();
        if (cur > dp[x][i]) {
            continue;
        }
        for (auto [y, j] : adj[x]) {
            if (i == 0) {
                if (dp[y][j] > dp[x][i] + j * j) {
                    dp[y][j] = dp[x][i] + j * j;
                    q.emplace(dp[y][j], y, j);
                } 
            } else {
                if (dp[y][0] > dp[x][i] + j * j + 2 * i * j) {
                    dp[y][0] = dp[x][i] + j * j + 2 * i * j;
                    q.emplace(dp[y][0], y, 0);
                } 
            }   
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i][0] == inf) {
            cout << -1 << " \n"[i == n - 1];
        } else {
            cout << dp[i][0] << " \n"[i == n - 1];
        }
    }

    return 0;
}
