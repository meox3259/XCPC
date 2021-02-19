#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;

        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (n % 2 == 1) {
            cout << 1 << '\n';
        } else {
            cout << 1LL * (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << '\n';
        }
    }

    return 0;
}
