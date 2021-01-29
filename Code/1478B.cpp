#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int q, d;
        cin >> q >> d;

        while (q --) {
            int a;
            cin >> a;

            bool ok = false;
            if (a >= d * 10) {
                ok = true;
            }

            for (int i = 1; i <= 10; ++i) {
                if (d * i % 10 == a % 10 && d * i <= a) {
                    ok = true;
                }
            }

            if (ok) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
