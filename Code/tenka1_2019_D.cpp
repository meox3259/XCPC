#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = 0;
    for (int i : a) {
        m += i;
    }

    vector<vector<long long> > dp(n + 1, vector<long long> (m + m + 1));
    dp[0][m] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= m + m; ++j) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]] * 2) % P;
        }
        for (int j = 0; j + a[i] <= m + m; ++j) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j + a[i]]) % P; 
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = ans * 3 % P;
    }

    for (int i = 0; i <= m; ++i) {
        ans = (ans - dp[n][i] * 3 % P + P) % P;
    }

    if (m % 2 == 0) {
        vector<vector<long long> > f(n + 1, vector<long long> (m + m + 1));
        f[0][m] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = a[i]; j <= m + m; ++j) {
                f[i + 1][j] = (f[i + 1][j] + f[i][j - a[i]]) % P;
            }
            for (int j = 0; j + a[i] <= m + m; ++j) {
                f[i + 1][j] = (f[i + 1][j] + f[i][j + a[i]]) % P;
            }
        }
        ans = (ans + f[n][m] * 3 % P + P) % P;
    }

    cout << ans << '\n';

    return 0;
}
