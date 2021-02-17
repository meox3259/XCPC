#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] --;
        }

        vector<vector<int> > pos(n);
        for (int i = 0; i < n; ++i) {
            pos[a[i]].emplace_back(i);
        }

        vector<int> ans(n, inf);
        for (int i = 0; i < n; ++i) {
            int Max = 0;
            if (!pos[i].empty()) {
                Max = max(Max, pos[i][0]);
                Max = max(Max, n - 1 - pos[i].back());
                for (int j = 0; j + 1 < pos[i].size(); ++j) {
                    Max = max(Max, pos[i][j + 1] - pos[i][j] - 1);
                }
                ans[Max] = min(ans[Max], i);
            }
        }
        
        for (int i = 0; i + 1 < n; ++i) {
            ans[i + 1] = min(ans[i + 1], ans[i]);
        }

        for (int i = 0; i < n; ++i) {
            cout << (ans[i] == inf ? -1 : ans[i] + 1) << " \n"[i == n - 1];
        }
    }

    return 0;
}
