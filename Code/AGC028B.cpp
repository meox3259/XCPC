#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

long long power(long long x, long long t) {
    long long ret= 1;
    for (; t; t >>= 1, x = x * x % P) {
        if (t & 1) {
            ret = ret * x % P;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % P;
    }

    vector<long long> facinv(n + 1);
    facinv[n] = power(fac[n], P - 2);
    for (int i = n; i >= 1; --i) {
        facinv[i - 1] = facinv[i] * i % P;
    }

    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = (pre[i - 1] + fac[n] * facinv[i] % P * fac[i - 1] % P) % P;
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * (pre[i + 1] + pre[n - i] - pre[1] + P) % P;
        ans %= P;
    }

    cout << ans << '\n';

    return 0;
}
