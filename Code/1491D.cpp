#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q --) {
        int u, v;
        cin >> u >> v;

        bool ok = true;
        if (__builtin_popcount(u) >= __builtin_popcount(v) && u <= v) {
            vector<int> bu(40);
            vector<int> bv(40);
            for (int i = 0; i < 31; ++i) {
                bu[i] = (u >> i) & 1;
                bv[i] = (v >> i) & 1;
            }

            for (int i = 0; i < 31; ++i) {
                bu[i + 1] += bu[i];
                bv[i + 1] += bv[i];
            }

            bool big = false;
            for (int i = 0; i < 40; ++i) {
                if (bv[i] > bu[i]) {
                    big = true;
                }
            }
            if (big) {
                ok = false;
            }
        } else {
            ok = false;
        }

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
