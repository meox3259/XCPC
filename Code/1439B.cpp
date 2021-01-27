#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int> > adj(n);
        vector<int> deg(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            x --;
            y --;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
            deg[x] ++;
            deg[y] ++;
        }

        set<pair<int, int> > s;
        for (int i = 0; i < n; ++i) {
            s.emplace(deg[i], i);
        }

        vector<bool> del(n);
        while (!s.empty() && s.begin() -> first < k - 1) {
            auto [d, i] = *s.begin(); 
            s.erase(s.begin());
            for (int j : adj[i]) {
                if (!del[j]) {
                    s.erase(s.find(make_pair(deg[j], j)));
                    deg[j] --;
                    s.emplace(deg[j], j);
                } 
            }
            del[i] = true;
        }

        if (s.empty()) {
            cout << -1 << '\n';
        } else {
            auto full = [&] (set<pair<int, int> > s, vector<bool> del) -> bool {
                while (!s.empty() && s.begin() -> first < k) {
                    auto [d, i] = *s.begin();
                    s.erase(s.begin());
                    for (int j : adj[i]) {
                        if (!del[j]) {
                            s.erase(s.find(make_pair(deg[j], j)));
                            deg[j] --;
                            s.emplace(deg[j], j);
                        }
                    }
                    del[i] = true;
                }
                return !s.empty();
            };
            if (full(s, del)) {
                cout << 1 << ' ' << s.size() << '\n'; 
                for (auto it : s) {
                    cout << it.second + 1 << ' ';
                }
                cout << '\n';
            } else {
                cout << 2 << '\n';
                vector<int> node;
                vector<int> c(n, -1);
                auto dfs = [&] (auto &&f, int x) -> void {
                    vector<bool> vis(adj[x].size());
                    if (c[x] < adj[x].size()) {
                        vis[c[x]] = true;
                    }
                    for (int y : adj[x]) {
                        if (c[y] != -1 && c[y] < adj[x].size()) {
                            vis[c[y]] = true;
                        }
                    }  
                    int cur = 0;
                    vector<int> to;
                    for (int y : adj[x]) {
                        if (c[y] == -1) {
                            while (vis[cur]) {
                                cur ++;
                            }
                            c[y] = cur;
                            vis[cur] = true;
                            to.emplace_back(y);
                        }
                    }
                    for (int y : to) {
                        f(f, y);
                    }
                };
                for (auto it : s) {
                    node.emplace_back(it.second);
                }
                dfs(dfs, node[0]);
                map<vector<int>, vector<int> > mp;
                for (int i : node) {
                    vector<int> col;
                    col.emplace_back(c[i]);
                    for (int j : adj[i]) {
                        col.emplace_back(c[j]);
                    }
                    sort(col.begin(), col.end());
                    mp[col].emplace_back(i);
                }
                bool ok = false;
                for (auto o : mp) {
                    auto vec = o.second;
                    if (vec.size() == k) {
                        ok = true; 
                        cout << 2 << '\n';
                        for (int i = 0; i < k; ++i) {
                            cout << vec[i] + 1 << " \n"[i == k - 1];
                        }
                    }
                }
                if (!ok) {
                    cout << -1 << '\n';
                }
            }
        }
    }

    return 0;
}
