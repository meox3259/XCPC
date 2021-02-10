#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b * c) {
            cout << -1 << '\n';
        } else {
            auto calc = [&] () -> long long {
                long long t = a / b;
                long long pos = t / d * d;
                long long cnt = pos / d; 
                long long dmg = cnt * a + a;
                long long hel = b * pos * cnt;
                hel -= (d * b * cnt) * (cnt - 1) / 2;
                return dmg - hel;
            };
            cout << calc() << '\n';
        }
    }

    return 0;
}
