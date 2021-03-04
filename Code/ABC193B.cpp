#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p(n);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> x[i];
    }

    int ans = inf;
    for (int i = 0; i < n; ++i) {
        if (x[i] - a[i] > 0) {
            ans = min(ans, p[i]);
        }
    }

    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
