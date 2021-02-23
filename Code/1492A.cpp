#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;

        long long x = (a - p % a) % a;
        long long y = (b - p % b) % b;
        long long z = (c - p % c) % c;
        cout << min(x, min(y, z)) << '\n';
    }

    return 0;
}
