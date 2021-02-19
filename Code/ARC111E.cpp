#include <bits/stdc++.h>
#include <atcoder/math>

using namespace std;
using namespace atcoder;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long u = (d - 1) / (c - b);
        long long x = floor_sum(u, d, b, a + b - 1);
        long long y = floor_sum(u, d, c, a + c);
        cout << u - y + x << '\n';
    }

    return 0;
}
