#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;

const int P = 1000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<vector<int> > a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[i][j] - 'a';
        }
    }

    vector<int> fi;
    vector<int> se;
    vector<int> id;
    vector<bool> vis(n);
    vector<int> pal(P);
    vector<int> cnt(P);
    vector<int> rev(P);
    vector<int> x;
    vector<int> y;
    vector<int> z;
    auto dfs = [&] (auto &&f, int p) -> void {
        if (fi.size() + n - p < n / 2) {
            return;
        }
        if (fi.size() == n / 2) {
            for (int i = 0; i < n; ++i) {
                vis[i] = false;
            }
            for (int i : fi) {
                vis[i] = true;
            }
            se.clear();
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) {
                    se.emplace_back(i);
                }
            }
            do {
                id.clear();
                x.clear();
                y.clear();
                z.clear();
                for (int i : fi) {
                    id.emplace_back(i);
                }
                for (int i : se) {
                    id.emplace_back(i);
                }
                for (int j = 0; j < m; ++j) {
                    int h = 0;
                    int g = 0;
                    for (int i = 0; i < n; ++i) {
                        h = (h * 137 + a[id[i]][j]) % P;
                    }
                    for (int i = n - 1; i >= 0; --i) {
                        g = (g * 137 + a[id[i]][j]) % P;
                    }
                    if (h == g) {
                        z.emplace_back(h); 
                        pal[h] ++;
                    } else {
                        x.emplace_back(h);
                        y.emplace_back(g);
                        cnt[h] ++;
                        rev[g] ++;
                    }
                }
                bool ok = true;
                int odd = 0;
                for (int i : z) {
                    odd += (pal[i] & 1);
                    pal[i] = 0;
                }
                if (odd != (m & 1)) {
                    for (int i : x) {
                        cnt[i] = 0;
                    }
                    for (int i : y) {
                        rev[i] = 0;
                    }
                    continue;
                }
                for (int i : x) {
                    if (cnt[i] != rev[i]) {
                        ok = false;
                    }
                }
                for (int i : x) {
                    cnt[i] = 0;
                }
                for (int i : y) {
                    rev[i] = 0;
                }
                if (!ok) {
                    continue;
                }
                cout << "YES" << '\n';
                exit(0);
            } while (next_permutation(se.begin(), se.end()));
            return; 
        } 

        for (int i = p; i < n; ++i) {
            fi.emplace_back(i);
            f(f, i + 1);
            fi.pop_back();
        }
    };

    dfs(dfs, 0);

    cout << "NO" << '\n';

    return 0;
}
