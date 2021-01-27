#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

    while (T --) {
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        vector<vector<int> > a(n, vector<int> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = s[i][j] - '0';
            }
        }

        vector<vector<pair<int, int> > > ans;

        if ((n & 1) && (m & 1)) {
            vector<pair<int, int> > opr;
            if (a[n - 1][m - 1] == 1) {
                opr.emplace_back(n - 1, m - 1);
                opr.emplace_back(n - 2, m - 1);
                opr.emplace_back(n - 1, m - 2);
                a[n - 1][m - 1] ^= 1;
                a[n - 2][m - 1] ^= 1;
                a[n - 1][m - 2] ^= 1;
                ans.push_back(opr);
            }
        }

        if (n & 1) {
            for (int i = 0; i + 1 < m; i += 2) {
                if (a[n - 1][i] == 1 || a[n - 1][i + 1] == 1) {
                    vector<pair<int, int> > opr;
                    int need = 3;
                    if (a[n - 1][i] == 1) {
                        opr.emplace_back(n - 1, i);
                        need --;
                        a[n - 1][i] ^= 1;
                    }
                    if (a[n - 1][i + 1] == 1) {
                        opr.emplace_back(n - 1, i + 1);
                        need --;
                        a[n - 1][i + 1] ^= 1;
                    }
                    if (need == 1) {
                        opr.emplace_back(n - 2, i);
                        a[n - 2][i] ^= 1;
                    } 
                    if (need == 2) {
                        opr.emplace_back(n - 2, i);
                        opr.emplace_back(n - 2, i + 1);
                        a[n - 2][i] ^= 1;
                        a[n - 2][i + 1] ^= 1;
                    }
                    ans.push_back(opr);
                }  
            }
        }

        if (m & 1) {
            for (int i = 0; i + 1 < n; i += 2) {
                if (a[i][m - 1] == 1 || a[i + 1][m - 1] == 1) {
                    vector<pair<int, int> > opr;
                    int need = 3;
                    if (a[i][m - 1] == 1) {
                        opr.emplace_back(i, m - 1);
                        need --;
                        a[i][m - 1] ^= 1;
                    }
                    if (a[i + 1][m - 1] == 1) {
                        opr.emplace_back(i + 1, m - 1);
                        need --;
                        a[i + 1][m - 1] ^= 1;
                    }
                    if (need == 1) {
                        opr.emplace_back(i, m - 2);
                        a[i][m - 2] ^= 1;
                    }
                    if (need == 2) {
                        opr.emplace_back(i, m - 2);
                        opr.emplace_back(i + 1, m - 2);
                        a[i][m - 2] ^= 1;
                        a[i + 1][m - 2] ^= 1;
                    }
                    ans.push_back(opr);
                }                
            }
        }

        for (int i = 0; i + 1 < n; i += 2) {
            for (int j = 0; j + 1 < m; j += 2) {
                int cnt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]; 
                vector<vector<pair<int, int> > > c(2);
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        c[a[i + x][j + y]].emplace_back(x + i, y + j);
                    }
                }
                if (cnt == 1) {
                    vector<pair<int, int> > opr;
                    auto [x, y] = c[1][0];
                    opr.emplace_back(x, y);
                    opr.emplace_back(x ^ 1, y);
                    opr.emplace_back(x, y ^ 1);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x, y);
                    opr.emplace_back(x ^ 1, y ^ 1);
                    opr.emplace_back(x ^ 1, y);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x, y);
                    opr.emplace_back(x ^ 1, y ^ 1);
                    opr.emplace_back(x, y ^ 1);
                    ans.push_back(opr);
                } else if (cnt == 2) {
                    vector<pair<int, int> > opr;
                    auto [x0, y0] = c[1][0];
                    auto [x1, y1] = c[1][1];
                    auto [x2, y2] = c[0][0];
                    auto [x3, y3] = c[0][1];
                    opr.emplace_back(x0, y0);
                    opr.emplace_back(x2, y2);
                    opr.emplace_back(x3, y3);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x1, y1);
                    opr.emplace_back(x2, y2);
                    opr.emplace_back(x3, y3);
                    ans.push_back(opr);
                } else if (cnt == 3) {
                    ans.push_back(c[1]);
                } else if (cnt == 4) {
                    vector<pair<int, int> > opr;
                    int x = i + 1;
                    int y = j + 1;
                    opr.emplace_back(x ^ 1, y);
                    opr.emplace_back(x, y ^ 1);
                    opr.emplace_back(x ^ 1, y ^ 1);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x, y);
                    opr.emplace_back(x ^ 1, y);
                    opr.emplace_back(x, y ^ 1);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x, y);
                    opr.emplace_back(x ^ 1, y ^ 1);
                    opr.emplace_back(x ^ 1, y);
                    ans.push_back(opr);
                    opr.clear();
                    opr.emplace_back(x, y);
                    opr.emplace_back(x, y ^ 1);
                    opr.emplace_back(x ^ 1, y ^ 1);
                    ans.push_back(opr);
                }
            }
        }

        cout << ans.size() << '\n';
        for (auto vec : ans) {
            for (auto [x, y] : vec) {
                cout << x + 1 << ' ' << y + 1 << ' ';
            }
            cout << '\n';
        }
    }

	return 0;
}
