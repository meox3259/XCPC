#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long a, b;
        cin >> a >> b;

        long long ans = 0;
        for (long long x = 1; x <= 300000; ++x) {
            long long up = min(a, b * x + x);
            ans += max(0LL, up / x - x - 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
