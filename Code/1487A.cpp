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

        int Min = *min_element(a.begin(), a.end());
        int ans = 0;
        for (int i : a) {
            if (i > Min) {
                ans ++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
