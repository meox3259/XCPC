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

        vector<long long> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        long long ans = 0;
        long long pre = abs(a[1] - b[1]) * 2;
        for (int i = 1; i < n; ++i) {
            if (a[i] == b[i]) {
                pre = c[i] + 1;
            } else {
                pre += c[i] + 1;
                pre -= abs(a[i] - b[i]);
                pre = max(pre, c[i] + 1 + abs(a[i] - b[i]));
            }
            ans = max(ans, pre);
        }

        cout << ans << '\n';
    }

    return 0;
}
