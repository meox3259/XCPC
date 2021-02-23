#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> c;
    for (int i = 0; i < n; ++i) {
        c.emplace_back(a[i]);
        c.emplace_back(b[i]);
    }

    sort(c.begin(), c.end());
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + c[i];
    }

    long long ans = min(accumulate(a.begin(), a.end(), 0LL), accumulate(b.begin(), b.end(), 0LL));
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        int y = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        if (x > y) {
            swap(x, y);
        }
        if (y < n - 1) {
            ans = min(ans, sum[n]);
        } else if (x < n - 2) {
            ans = min(ans, sum[n - 1] + c[y]);
        } else {
            ans = min(ans, sum[n - 2] + a[i] + b[i]);
        }
    }

    cout << ans << '\n';

    return 0;
}
