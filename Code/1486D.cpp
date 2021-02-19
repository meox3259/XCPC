#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0;
    int r = n + 1;

    auto check = [&] (int mid) -> bool {
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (a[i] >= mid ? 1 : -1);
        }
        int Min = 0;
        for (int i = k, j = 0; i <= n; ++i, ++j) {
            Min = min(Min, pre[j]);
            if (pre[i] - Min >= 1) {
                return true;
            }
        }
        return false;
    };

    while (r - l > 1) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';

    return 0;
}
