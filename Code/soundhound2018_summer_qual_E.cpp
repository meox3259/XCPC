#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int> > > adj(n);
    vector<tuple<int, int, int> > edge;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        x --;
        y --;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
        edge.emplace_back(x, y, w);
    }

    vector<long long> dis(n);
    vector<int> col(n, -1);
    vector<bool> vis(n);
    long long low = 1;
    long long high = inf;

    auto color = [&] (auto &&f, int x) -> void {
        for (auto [y, w] : adj[x]) {
            if (col[y] == -1) {
                col[y] = col[x] ^ 1;
                f(f, y);
            } 
        }
    };

    bool ok = true;
    auto dfs = [&] (auto &&f, int x) -> void {
        for (auto [y, w] : adj[x]) {
            if (!vis[y]) {
                dis[y] = w - dis[x];
                vis[y] = true;
                f(f, y);
            }
            if (dis[y] != w - dis[x]) {
                ok = false;
            }
            if (col[x] == col[y]) {
                auto check = [&] (long long tot) -> bool {
                    long long s = tot / 2;
                    if (tot % 2 != 0 || s <= 0) {
                        return false;
                    }
                    queue<int> q;
                    vector<long long> val(n);
                    vector<bool> visit(n);
                    visit[0] = true;
                    q.emplace(0);
                    val[0] = s;
                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (auto [v, w] : adj[u]) {
                            if (!visit[v]) {
                                visit[v] = true;
                                val[v] = w - val[u];
                                q.emplace(v);
                            }
                        }
                    }
                    bool ok = true;
                    for (auto [u, v, w] : edge) {
                        if (val[u] + val[v] != w || val[u] <= 0 || val[v] <= 0) {
                            ok = false;
                        }
                    }
                    return ok;
                };
                if (check(dis[x] + dis[y] - w) || check(w - dis[x] - dis[y])) {
                    cout << 1 << '\n';
                } else {
                    cout << 0 << '\n';
                }
                exit(0);
            } 
        }
    };

    col[0] = 0;
    color(color, 0);
    vis[0] = true;
    dfs(dfs, 0);

    for (int i = 1; i < n; ++i) {
        if (col[i] == 0) {
            low = max(low, 1 - dis[i]);
        } else {
            high = min(high, dis[i] - 1);
        }
    }

    if (!ok) {
        cout << 0 << '\n';
    } else {
        cout << max(0LL, high - low + 1) << '\n';
    }

    return 0;
}
