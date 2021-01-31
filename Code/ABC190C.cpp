#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i] --;
        b[i] --;
    }

    int k;
    cin >> k;

    vector<int> c(k);
    vector<int> d(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i] >> d[i];
        c[i] --;
        d[i] --;
    }

    int ans = 0;
    for (int S = 0; S < 1 << k; ++S) {
        vector<bool> hav(n);
        for (int i = 0; i < k; ++i) {
            if (S >> i & 1) {
                hav[c[i]] = true; 
            } else {
                hav[d[i]] = true;
            }
        }
        int tot = 0;
        for (int i = 0; i < m; ++i) {
            if (hav[a[i]] && hav[b[i]]) {
                tot ++;
            }
        }
        ans = max(ans, tot);
    }

    cout << ans << '\n';

    return 0;
}
