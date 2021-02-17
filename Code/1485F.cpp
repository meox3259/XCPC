#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + b[i];
        }

        unordered_map<long long, int> mp;
        vector<vector<long long> > dp(n + 1, vector<long long> (2));
        dp[1][1] = 1;
        mp[pre[0]] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % P;
            dp[i][0] = (dp[i][1] - mp[pre[i - 1]] + P) % P; 
            mp[pre[i - 1]] = (mp[pre[i - 1]] + dp[i][0]) % P;
        }

        cout << (dp[n][0] + dp[n][1]) % P << '\n';
    }

    return 0;
}
