#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        long long u, v;
        cin >> n >> u >> v;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool diff = false;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[0]) {
                diff = true;
            }
        }

        bool con = true;
        for (int i = 0; i < n - 1; ++i) {
            if (abs(a[i] - a[i + 1]) > 1) {
                con = false;
            }
        }

        long long ans = numeric_limits<long long> :: max();
        if (!con) {
            cout << 0 << '\n';
            continue;
        } 
        if (!diff) {
            ans = min(v + v, u + v); 
        } else {
            ans = min(u, v);
        }
        cout << ans << '\n';
    }

    return 0;
}
