#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                for (int j = i - k; j >= 0; j -= k) {
                    if (s[j] == '?') {
                        s[j] = s[i];
                    } else if (s[j] == s[i]) {
                        break;
                    } else {
                        ok = false;
                        break;
                    }
                }
                for (int j = i + k; j < n; j += k) {
                    if (s[j] == '?') {
                        s[j] = s[i];
                    } else if (s[j] == s[i]) {
                        break;
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
        }

        vector<vector<int> > pre(n + 1, vector<int> (2));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                pre[i + 1][j] = pre[i][j];
            }
            if (s[i] != '?') {
                pre[i + 1][s[i] - '0'] ++;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i >= k) {
                if (pre[i][0] - pre[i - k][0] > k / 2 || pre[i][1] - pre[i - k][1] > k / 2) {
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
