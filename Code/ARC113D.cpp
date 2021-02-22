#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

long long power(long long x, long long t) {
    long long ret = 1;
    for (; t; t >>= 1, x = x * x % P) {
        if (t & 1) {
            ret = ret * x % P;
        }
    }
    return ret;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (m == 1) {
        cout << power(k, n) << '\n';
        exit(0);
    }

    if (n == 1) {
        long long ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += power(k - i + 1, m);
            ans -= power(k - i, m);
            ans += P;
            ans %= P;
        }
        cout << ans << '\n';
        exit(0);
    }

    long long ans = 0;
    for (int i = 1; i <= k; ++i) {
        long long row = 0;
        long long col = 0;
        row += power(i, n);
        row -= power(i - 1, n);
        row += P;
        row %= P;
        col += power(k - i + 1, m);
        ans += col * row % P;
        ans %= P;
    }

    cout << ans << '\n';

    return 0;
}
