#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string s;
        cin >> s;

        bool ok = true;
        vector<long long> bit(64);
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                for (int j = 0; j < 63; ++j) {
                    if (a[i] >> j & 1) {
                        if (!bit[j]) {
                            bit[j] = a[i];
                            break;
                        } else {
                            a[i] ^= bit[j];
                        }
                    }
                } 
            } else {
                for (int j = 0; j < 63; ++j) {
                    if (a[i] >> j & 1) {
                        if (!bit[j]) {
                            ok = false;
                        } else {
                            a[i] ^= bit[j];
                        }
                    }
                }
                if (a[i] != 0) {
                    ok = false;
                }
            }
        }

        if (ok) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }

    return 0;
}
