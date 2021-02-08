#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > dp(n, vector<int> (n, -1));
    auto dfs = [&] (auto &&f, int l, int r) -> int {
        if (r - l < 2) {
            return 0;
        }  
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        dp[l][r] = max(f(f, l, r - 1), f(f, l + 1, r));
        for (int i = l; i < r; ++i) {
            if ((i - l - 1) % 3 == 0 && (r - i - 1) % 3 == 0) {
                dp[l][r] = max(dp[l][r], f(f, l + 1, i - 1) + f(f, i + 1, r - 1) + a[l] + a[i] + a[r]);
            } 
            dp[l][r] = max(dp[l][r], f(f, l, i) + f(f, i + 1, r));
        }
        return dp[l][r];
    };  

    cout << dfs(dfs, 0, n - 1) << '\n';

    return 0;
}
