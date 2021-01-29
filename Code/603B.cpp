#include <bits/stdc++.h>

using namespace std;

const int P = 1000000000 + 7;

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
    int p, k;
    cin >> p >> k;

    if (k == 0) {
        cout << power(p, p - 1) << '\n';
        exit(0);
    }

    vector<bool> vis(p);
    vector<int> tot(p + 1);
    for (int i = 0; i < p; ++i) {
        if (!vis[i]) {
            int cur = i;
            int cnt = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cnt ++;
                cur = 1LL * k * cur % p;
            }
            tot[cnt] ++;
        }
    }

    vector<long long> fac(p + 1);
    fac[0] = 1;
    for (int i = 1; i <= p; ++i) {
        fac[i] = fac[i - 1] * i % P;
    }

    long long ans = 1;
    for (int i = 1; i <= p; ++i) {
        if (tot[i] != 0) {
            for (int j = 0; j < tot[i]; ++j) {
                ans = ans * (1LL * tot[i] * i % P + (i != 1)) % P;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
