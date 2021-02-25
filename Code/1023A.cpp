#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (n > m + 1) {
        cout << "NO" << '\n';
        exit(0);
    }

    int p = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            p = i;
        }
    }

    if (p == -1) {
        if (s == t) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        exit(0);
    }

    bool ok = true;
    for (int i = 0; i < p; ++i) {
        if (s[i] != t[i]) {
            ok = false;
        }
    }

    for (int i = n - 1, j = m - 1; i > p; --i, --j) {
        if (s[i] != t[j]) {
            ok = false;
        }
    }

    if (ok) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
