#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        bool ok = false;
        int cur = -1;
        for (int _ = 0; _ < k; ++_) {
            for (int i = 0; i < n; ++i) {
                if (i == n - 1) {
                    cur = -1;
                    break;
                }
                if (h[i] < h[i + 1]) {
                    h[i] ++;
                    cur = i + 1;
                    break;
                }
            }
            if (cur == -1) {
                break;
            }
        }

        cout << cur << '\n';
    }

    return 0;
}
