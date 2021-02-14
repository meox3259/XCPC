#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, n;
    cin >> r >> n;

    vector<tuple<int, int, int> > p(n + 1);
    p[0] = { 0, 1, 1 };
    for (int i = 1; i <= n; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        p[i] = { t, x, y };
    }

    vector<vector<int> > mp(r + 1, vector<int> (r + 1, -inf));

    vector<int> dp(n + 1, -inf);
    vector<int> tag(n + 1, -inf);
    dp[0] = 0;
    for (int i = 0, j = 0; i <= n; ++i) {
        auto [ti, xi, yi] = p[i];
        dp[i] = max(dp[i], tag[i] + 1);
        if (i < n) {
            tag[i + 1] = max(tag[i + 1], tag[i]);
        }
        for (int j = i + 1; j <= n; ++j) {
            auto [tj, xj, yj] = p[j];
            if (tj - ti > 1000) {
                tag[j] = max(tag[j], dp[i]);
                break;
            }
            if (tj - ti >= abs(xi - xj) + abs(yi - yj)) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
