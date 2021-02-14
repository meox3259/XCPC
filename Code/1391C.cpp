#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;

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
    int n;
    cin >> n;

    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans = ans * i % P;
    }

    vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % P; 
    }

    auto C = [&] (int n, int m) -> long long {
        return fac[n] * power(fac[m], P - 2) % P * power(fac[n - m], P - 2) % P;
    };

    for (int i = 1; i <= n; ++i) {
        ans = (ans - C(n - 1, i - 1) + P) % P;
    }

    cout << ans << '\n';

    return 0;
}
