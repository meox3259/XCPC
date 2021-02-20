#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = inf;

    for (int i = 0; i < n; ++i) {
        ans = min(ans, x - a[i]);
    }

    for (int m = 2; m <= n; ++m) {
        int l = x % m; 
        vector<vector<vector<long long> > > dp(2, vector<vector<long long> > (m + 1, vector<long long> (m, -inf)));
        dp[0][0][0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur ^= 1;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k < m; ++k) {
                    dp[cur][j][k] = dp[cur ^ 1][j][k];
                }
            }
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < m; ++k) {
                    dp[cur][j + 1][(k + a[i]) % m] = max(dp[cur][j + 1][(k + a[i]) % m], dp[cur ^ 1][j][k] + a[i]);
                }
            } 
        }
        if (dp[cur][m][l] > 0) {
            ans = min(ans, (x - dp[cur][m][l]) / m);
        }
    }

    cout << ans << '\n';

    return 0;
}
