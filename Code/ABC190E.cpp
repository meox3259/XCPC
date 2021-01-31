#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i] --;
        b[i] --;
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }

    int k;
    cin >> k;

    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
        c[i] --;
    }

    vector<vector<int> > d(k, vector<int> (n, -1));
    for (int i = 0; i < k; ++i) {
        queue<int> q;
        q.emplace(c[i]);
        d[i][c[i]] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : adj[x]) {
                if (d[i][y] == -1) {
                    d[i][y] = d[i][x] + 1;
                    q.emplace(y);
                }
            }
        }
    }

    vector<vector<int> > dp(1 << k, vector<int> (k, inf));
    for (int i = 0; i < k; ++i) {
        dp[1 << i][i] = 1;
    }
    for (int S = 0; S < 1 << k; ++S) {
        for (int i = 0; i < k; ++i) {
            if (S >> i & 1) {
                for (int j = 0; j < k; ++j) {
                    if (!(S >> j & 1) && d[i][c[j]] != -1) {
                        dp[S ^ (1 << j)][j] = min(dp[S ^ (1 << j)][j], dp[S][i] + d[i][c[j]]);
                    }
                }
            }
        }
    }

    int ans = *min_element(dp[(1 << k) - 1].begin(), dp[(1 << k) - 1].end());

    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
