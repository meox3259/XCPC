#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    X --;
    Y --;

    vector<vector<tuple<int, int, int> > > adj(n);
    for (int i = 0; i < m; ++i) {
        int x, y, t, k;
        cin >> x >> y >> t >> k;
        x --;
        y --;
        adj[x].emplace_back(y, t, k);
        adj[y].emplace_back(x, t, k);
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<long long> dis(n, inf);
    dis[X] = 0;
    q.emplace(0, X);
    
    while (!q.empty()) {
        auto [cur, x] = q.top();
        q.pop();
        if (cur > dis[x]) {
            continue;
        }
        for (auto [y, t, k] : adj[x]) {
            if (dis[y] > dis[x] + t + (k - dis[x] % k) % k) {
                dis[y] = dis[x] + t + (k - dis[x] % k) % k;
                q.emplace(dis[y], y);
            } 
        }
    }

    if (dis[Y] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dis[Y] << '\n';
    }

    return 0;
}
