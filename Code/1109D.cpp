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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a --;
    b --;

    int N = max(n, m);
    vector<long long> fac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fac[i] = fac[i - 1] * i % P;
    }

    vector<long long> facinv(N + 1);
    facinv[N] = power(fac[N], P - 2);
    for (int i = N; i >= 1; --i) {
        facinv[i - 1] = facinv[i] * i % P;
    }

    auto C = [&] (int n, int m) -> long long {
        if (n < m) {
            return 0LL;
        }  
        return fac[n] * facinv[m] % P * facinv[n - m] % P;
    };

    vector<long long> pwm(n + 1);
    pwm[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pwm[i] = pwm[i - 1] * m % P;
    }

    vector<long long> pwn(n + 1);
    pwn[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pwn[i] = pwn[i - 1] * n % P;
    }

    long long ans = 0;
    for (int i = 2; i < n; ++i) {
        long long d = C(n - 2, i - 2) * i % P * pwn[n - i - 1] % P * fac[i - 2] % P * C(m - 1, i - 2) % P * pwm[n - i] % P;
        ans += d;
        ans %= P;
    } 

    ans += fac[n - 2] * C(m - 1, n - 2) % P;
    ans %= P;
    
    cout << ans << '\n';

    return 0;
}
