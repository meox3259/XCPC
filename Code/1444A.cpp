#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long p, q;
        cin >> p >> q;

        if (p % q != 0) {
            cout << p << '\n';
        } else {
            long long ans = -1;
            long long tmp = p / q;
            vector<long long> fac;
            for (long long i = 2; i * i <= q; ++i) {
                if (q % i == 0) {
                    long long c1 = 0;
                    while (tmp % i == 0) {
                        tmp /= i;
                        c1 ++;
                    }
                    long long c2 = 0;
                    while (q % i == 0) {
                        q /= i;
                        c2 ++;
                    }
                    long long t = 1;
                    for (int j = 0; j < c1 + 1; ++j) {
                        t = t * i;
                    }
                    fac.emplace_back(t);
                }
            }
            if (q > 1) {
                long long t = q;
                while (tmp % q == 0) {
                    tmp /= q;
                    t *= q;
                }
                fac.emplace_back(t);
            }
            cout << p / *min_element(fac.begin(), fac.end()) << '\n';
        }
    }

    return 0;
}
