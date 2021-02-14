#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    if (n >= 4) {
        cout << -1 << '\n';
        exit(0);
    }

    vector<vector<int> > a(n, vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[i][j] - '0';
        }
    }

    if (n == 1) {
        cout << 0 << '\n';
        exit(0);
    }

    if (n == 2) {
        vector<vector<int> > dp(m + 1, vector<int> (3, inf));
        for (int i = 0; i < 3; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int cnt = a[0][i] + a[1][i]; 
            dp[i + 1][0] = dp[i][1] + cnt;
            dp[i + 1][1] = min(dp[i][0], dp[i][2]) + abs(cnt - 1);
            dp[i + 1][2] = dp[i][1] + 2 - cnt;
        }
        cout << min(dp[m][0], min(dp[m][1], dp[m][2])) << '\n';
        exit(0);
    }

    if (n == 3) {
        vector<vector<int> > dp(m + 1, vector<int> (8, inf));
        for (int S = 0; S < 8; ++S) {
            dp[0][S] = 0;
        }
        for (int i = 0; i < m; ++i) {
            for (int S = 0; S < 8; ++S) {
                int cnt = 0;
                for (int j = 0; j < 3; ++j) {
                    if ((S >> j & 1) != a[j][i]) {
                        cnt ++;
                    }
                }
                for (int T = 0; T < 8; ++T) {
                    int x = (S & 1) + (S >> 1 & 1) + (T & 1) + (T >> 1 & 1);
                    int y = (S >> 1 & 1) + (S >> 2 & 1) + (T >> 1 & 1) + (T >> 2 & 1);
                    if ((x & 1) && (y & 1)) {
                        dp[i + 1][S] = min(dp[i + 1][S], dp[i][T] + cnt);
                    }
                }
            } 
        }        

        cout << *min_element(dp[m].begin(), dp[m].end()) << '\n';
    }

    return 0;
}
