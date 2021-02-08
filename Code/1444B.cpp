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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n + n);
    for (int i = 0; i < n + n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + P - a[i]) % P;
    }
    for (int i = n; i < n + n; ++i) {
        sum = (sum + a[i]) % P;
    }

    for (int i = 1; i <= n + n; ++i) {
        sum = sum * i % P;
    }
    for (int i = 1; i <= n; ++i) {
        long long inv = power(i, P - 2);
        sum = sum * inv % P;
        sum = sum * inv % P;
    }

    cout << sum << '\n';

    return 0;
}
