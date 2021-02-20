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
        vector<int> ans(n);
        int t = n;
        for (int i = n - 1; i >= 0; --i) {
            if (t >= 4) {
                ans[i] = 8;
            } else {
                if (t == 0) {
                    ans[i] = 9;
                } else {
                    if (t == 3) {
                        ans[i] = 8;
                    }
                    if (t == 2) {
                        ans[i] = 8;
                    }
                    if (t == 1) {
                        ans[i] = 8;
                    }
                }
            }
            t -= min(t, 4);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i]; 
        }
        cout << '\n';
    }

    return 0;
}
