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

        vector<long long> d(n + n);
        for (int i = 0; i < n + n; ++i) {
            cin >> d[i];
        }

        sort(d.begin(), d.end(), greater<long long> ());

        bool ok = true;
        for (int i = 0; i < n + n; i += 2) {
            if ((i > 0 && d[i] == d[i - 1]) || d[i] != d[i + 1]) {
                ok = false;
            }
        }

        long long sum = 0;
        for (int i = 0; i < n + n; i += 2) {
            if (((d[i] - sum) % (n + n - i)) != 0 || d[i] <= sum) {
                ok = false;
            }
            sum += 2 * (d[i] - sum) / (n + n - i);
        }

        if (ok) {
            cout << "YES" << '\n'; 
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
