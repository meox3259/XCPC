#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    long long k;
    cin >> n >> q >> k;

    vector<long long> a(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    a[0] = 0;
    a[n + 1] = k + 1;

    vector<long long> pre(n + 1);
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        v[i] = a[i + 1] - 1 - (a[i - 1] + 1); 
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = v[i] + pre[i - 1];
    }

    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << k - (a[r - 1] + 1) + pre[r - 1] - pre[l] + (a[l + 1] - 1) - 1 << '\n';
    }

    return 0;
}
