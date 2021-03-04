#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> cnt(2);
    for (int i : a) {
        cnt[i] ++;
    }

    while (q --) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x --;
            cnt[a[x]] --;
            a[x] ^= 1;
            cnt[a[x]] ++;
        }
        if (t == 2) {
            int k;
            cin >> k;
            if (cnt[1] >= k) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}
