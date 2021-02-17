#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        long long a, b;
        cin >> a >> b;

        long long ans = numeric_limits<long long> :: max();
        for (int i = 0; i <= 100; ++i) {
            long long tmp = i;
            if (b + i != 1) {
                long long ta = a;
                while (ta > 0) {
                    ta /= (b + i);
                    tmp ++;
                }     
                ans = min(ans, tmp);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
