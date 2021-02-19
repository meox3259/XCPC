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

        vector<long long> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (h[i] < i) {
                ok = false;
                break;
            }    
            if (i + 1 < n) {
                h[i + 1] += h[i] - i;
                h[i] = i;
            }
        }

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
