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

        if (m & 1) {
            cout << "YES" << '\n';
            for (int i = 0; i < m + 1; ++i) {
                cout << (i & 1) + 1 << " \n"[i == m];
            }
            continue;
        }

        bool ok = false;
        int a = -1;
        int b = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i][j] == s[j][i]) {
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            cout << "YES" << '\n';
            for (int i = 0; i < m + 1; ++i) {
                if (i & 1) {
                    cout << a + 1 << " \n"[i == m];
                } else {
                    cout << b + 1 << " \n"[i == m];
                }
            }
            continue;
        }

        for (int i = 0; i < n; ++i) {
            int a = -1;
            int b = -1;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    if (s[i][j] == 'a') {
                        a = j;
                    } else {
                        b = j;
                    }
                }
            }
            if (a != -1 && b != -1) {
                ok = true;
                int k = m / 2;
                if (k & 1) {
                    cout << "YES" << '\n';
                    cout << a + 1 << ' ';
                    for (int j = 0; j < k; ++j) {
                        if (j & 1) {
                            cout << a + 1 << ' ';
                        } else {
                            cout << i + 1 << ' ';
                        }
                    }
                    for (int j = 0; j < k; ++j) {
                        if (j & 1) {
                            cout << i + 1 << " \n"[j == k - 1];
                        } else {
                            cout << b + 1 << " \n"[j == k - 1];
                        }
                    }
                } else {
                    cout << "YES" << '\n';
                    cout << i + 1 << ' ';
                    for (int j = 0; j < k; ++j) {
                        if (j & 1) {
                            cout << i + 1 << ' ';
                        } else {
                            cout << a + 1 << ' ';
                        }
                    }
                    for (int j = 0; j < k; ++j) {
                        if (j & 1) {
                            cout << i + 1 << " \n"[j == k - 1];
                        } else {
                            cout << b + 1 << " \n"[j == k - 1];
                        }
                    }
                }
                break;
            }
        }

        if (!ok) {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
