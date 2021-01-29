#include <bits/stdc++.h>

using namespace std;

#define double long double

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    cout << fixed << setprecision(15);
    if (m == 1) {
        cout << 1. << '\n';
        exit(0);
    }

    vector<vector<double> > dp(n + 1, vector<double> (n * m + 1));
    dp[0][0] = 1.;
    for (int i = 0; i < n; ++i) {
        vector<double> pre(n * m + 1);
        pre[0] = dp[i][0] / (double)(m - 1);
        for (int j = 1; j <= n * m; ++j) {
            pre[j] = pre[j - 1] + dp[i][j] / (double)(m - 1);
        }
        for (int j = 1; j <= n * m; ++j) {
            dp[i + 1][j] = pre[j - 1];
            if (j >= m + 1) {
                dp[i + 1][j] -= pre[j - m - 1];
            }
            if (j >= x[i]) {
                dp[i + 1][j] -= dp[i][j - x[i]] / (double)(m - 1);
            }
        }
    }

    int sum = 0;
    for (int i : x) {
        sum += i;
    }

    double ans = 1.; 
    for (int i = 0; i < sum; ++i) {
        ans += dp[n][i] * (m - 1);
    }

    cout << ans << '\n';

    return 0;
}
