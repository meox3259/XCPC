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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] --;
        }

        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i] --;
        }

        vector<int> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
            c[i] --;
        }

        vector<vector<int> > need(n);
        vector<vector<int> > can(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                need[b[i]].emplace_back(i);
            } else {
                can[b[i]].emplace_back(i);
            }
        }

        vector<int> ans(m);
        vector<int> tail;
        bool ok = true;
        for (int i = m - 1; i >= 0; --i) {
            if (!need[c[i]].empty()) {
                ans[i] = need[c[i]].back();
                tail.emplace_back(need[c[i]].back());
                need[c[i]].pop_back();
            } else {
                if (!can[c[i]].empty()) {
                    ans[i] = can[c[i]].back();
                    tail.emplace_back(can[c[i]].back());
                } else {
                    if (tail.empty()) {
                        ok = false;
                        break;
                    } else {
                        ans[i] = tail.back();
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!need[i].empty()) {
                ok = false;
            }
        }

        if (!ok) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            for (int i = 0; i < m; ++i) {
                cout << ans[i] + 1 << " \n"[i == m - 1];
            }
        }
    }

    return 0;
}
