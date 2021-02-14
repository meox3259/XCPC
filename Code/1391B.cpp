
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

        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i].back() != 'D') {
                ans ++;
            }
        }
        for (int j = 0; j < m - 1; ++j) {
            if (s[n - 1][j] != 'R') {
                ans ++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
