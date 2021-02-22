#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> c(26);
    for (int i = 0; i < 26; ++i) {
        cin >> c[i];
    }

    vector<vector<vector<vector<int> > > > f(n + 1, vector<vector<vector<int> > > (n + 1, vector<vector<int> > (2, vector<int> (2))));
    f[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    if (i > 1 && x == 0) {
                        f[i + 1][j][y][0] = (f[i + 1][j][y][0] + f[i][j][x][y] * 24LL % P) % P;
                    } else {
                        f[i + 1][j][y][0] = (f[i + 1][j][y][0] + f[i][j][x][y] * 25LL % P) % P;
                    }
                    if (x != 1) {
                        f[i + 1][j + 1][y][1] = (f[i + 1][j + 1][y][1] + f[i][j][x][y]) % P;
                    }
                }
            }
        }
    }

    vector<vector<vector<vector<vector<int> > > > > dp(2, vector<vector<vector<vector<int> > > > (n + 1, vector<vector<vector<int> > > (n + 1, vector<vector<int> > (3, vector<int> (3)))));

    int cur = 0;
    dp[0][0][0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        cur ^= 1;
        for (int j = 0; j <= i + 1; ++j) {
            for (int k = 0; k <= i + 1; ++k) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        dp[cur][j][k][x][y] = 0;
                    }
                }
            }
        }
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= i - j; ++k) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (i > 1 && x == 0) { 
                            dp[cur][j][k][y][0] = (dp[cur][j][k][y][0] + dp[cur ^ 1][j][k][x][y] * 23LL % P) % P; 
                        } else {
                            dp[cur][j][k][y][0] = (dp[cur][j][k][y][0] + dp[cur ^ 1][j][k][x][y] * 24LL % P) % P;
                        } 
                        if (x != 1) {
                            dp[cur][j + 1][k][y][1] = (dp[cur][j + 1][k][y][1] + dp[cur ^ 1][j][k][x][y]) % P;
                        }
                        if (x != 2) {
                            dp[cur][j][k + 1][y][2] = (dp[cur][j][k + 1][y][2] + dp[cur ^ 1][j][k][x][y]) % P;
                        }
                    }
                }
            }
        }       
    }

    int ans = 26 * 26;
    for (int i = 2; i < n; ++i) {
        ans = ans * 25LL % P;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = c[i] + 1; j <= n; ++j) {
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    ans = (ans - f[n][j][x][y] + P) % P;
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            for (int x = c[i] + 1; x <= n; ++x) {
                for (int y = c[j] + 1; y <= n; ++y) {
                    for (int a = 0; a < 3; ++a) {
                        for (int b = 0; b < 3; ++b) {
                            ans = (ans + dp[cur][x][y][a][b]) % P; 
                        }
                    }  
                }
            } 
        }
    }

    cout << ans << '\n';

    return 0;
}
