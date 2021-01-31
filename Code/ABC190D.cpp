#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    auto calc = [&] (long long l) {
        if ((n * 2 / l - l + 1) % 2 == 0) {
            return 2;
        } 
        return 0;
    };

    long long ans = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans += calc(i);
            if (i * i != n) {
                ans += calc(n / i);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
