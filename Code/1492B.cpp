#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i] --;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[p[i]] = i;
        }

        vector<bool> vis(n);
        vector<int> ans;
        int j = n - 1;
        while (!p.empty()) {
            while (j >= 0 && vis[j]) {
                j --;
            } 
            vector<int> st;
            while (!p.empty()) {
                int cur = p.back();
                vis[cur] = true;
                st.emplace_back(cur);
                p.pop_back();
                if (cur == j) {
                    break;
                }
            }
            while (!st.empty()) {
                ans.emplace_back(st.back());
                st.pop_back();
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " \n"[i == n - 1];
        }
    }

    return 0;
}
