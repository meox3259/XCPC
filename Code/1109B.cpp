#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    if (n & 1) {
        char c = s[0];
        bool same = true;
        for (int i = 0; i < n; ++i) {
            if (i != n / 2 && s[i] != s[0]) {
                same = false;
            }
        }
        if (same) {
            cout << "Impossible" << '\n';
            exit(0);
        }
        cout << 2 << '\n';
        exit(0);
    } else {
        bool same = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[0]) {
                same = false;
            }
        }
        if (same) {
            cout << "Impossible" << '\n';
            exit(0);
        }
        string pre = s.substr(0, n / 2);
        string suf = s.substr(n / 2, n / 2);
        if (pre != suf) {
            cout << 1 << '\n';
        } else {
            auto isp = [&] (string s) -> bool {
                string t(s);
                reverse(t.begin(), t.end());
                return s == t;
            };
            for (int i = 0; i < n; ++i) {
                string x = s.substr(0, i + 1);
                string y = s.substr(i + 1, n - i - 1);
                string t = y + x;
                if (s != t && isp(t)) {
                    cout << 1 << '\n';
                    exit(0);
                }
            }
            cout << 2 << '\n';
        }
        exit(0);
    }

    return 0;
}
