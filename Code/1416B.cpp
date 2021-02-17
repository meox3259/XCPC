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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long sum = 0;
        for (int i : a) {
            sum += i;
        }

        if (sum % n != 0) {
            cout << -1 << '\n';
            continue;
        }

        long long avg = sum / n;

        vector<tuple<int, int, int> > ans;

        for (int i = 1; i < n; ++i) {
            if (a[i] != 0) {
                int need = (i + 1 - a[i] % (i + 1)) % (i + 1);
                ans.emplace_back(0, i, need);
                ans.emplace_back(i, 0, (a[i] + need) / (i + 1));
            }
        }

        for (int i = 1; i < n; ++i) {
            ans.emplace_back(0, i, avg);
        }

        cout << ans.size() << '\n';
        for (auto [i, j, k] : ans) {
            cout << i + 1 << ' ' << j + 1 << ' ' << k << '\n';
        }
    }

    return 0;
}
