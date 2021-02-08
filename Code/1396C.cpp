#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> r(3);
    for (int i = 0; i < 3; ++i) {
        cin >> r[i];
    }

    long long d;
    cin >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> suf(n + 1);
    for (int i = 0; i < n; ++i) {
        suf[i + 1] = min(r[0] * (a[i] + 2), r[1] + r[0]);
    }

    suf[n] = min(suf[n] + d * 2, a[n - 1] * r[0] + r[2]);

    for (int i = n; i >= 1; --i) {
        suf[i - 1] += suf[i];
    }

    vector<long long> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + (i == 0 ? 0 : d) + a[i] * r[0] + r[2]);
        if (i + 2 <= n) {
            dp[i + 2] = min(dp[i + 2], 
                            dp[i] + d * 3 + min(a[i] * r[0] + r[0], r[1]) + min(a[i + 1] * r[0] + r[0], r[1]) + r[0] + r[0] + (i == 0 ? 0 : d));
        }
    }
    
    long long ans = dp[n];
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i] + suf[i + 1] + d * 2 * (n - 1 - i) + (i == 0 ? 0 : d));
    }

    cout << ans << '\n';

    return 0;
}
