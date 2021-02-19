#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    vector<vector<int> > dp(n + 1, vector<int> (m + 1));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
            }
            if (j < m) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1); 
            }
            if (i < n && j < m) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - 2 + 4 * (a[i] == b[j]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
