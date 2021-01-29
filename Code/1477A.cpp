#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        bool ok = false;
        for (auto i : x) {
            if (i == k) {
                ok = true;
            }
        }
        sort(x.begin(), x.end());
        long long g = 0;
        for (int i = 1; i < n; ++i) {
            g = __gcd(g, x[0] - x[i]);
        }
        if (ok || (k - x[0]) % g == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
