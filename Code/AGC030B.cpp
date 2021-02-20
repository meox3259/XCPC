#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, n;
    cin >> L >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    vector<int> d(n + 1);
    d[0] = h[0];
    for (int i = 1; i < n; ++i) {
        d[i] = h[i] - h[i - 1];
    }
    d[n] = L - h[n - 1];

    long long ans = 0;

    for (int _ = 0; _ < 2; ++_) {
        vector<long long> s(n + 2);
        for (int i = 0; i < n + 1; ++i) {
            s[i + 1] = s[i] + d[i];
        }
        vector<long long> t(n + 2);
        for (int i = 0; i < n + 1; ++i) {
            t[i + 1] = t[i] + 1LL * d[i] * i;
        }
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            sum -= t[(i + 1) / 2] * 2;
            sum += s[(i + 1) / 2] * i;
            sum += (t[i + 1] - t[(i + 3) / 2]) * 2;
            sum -= (s[i + 1] - s[(i + 3) / 2]) * (i + 1);
            sum += (s[n + 1] - s[i + 1]) * (i + 1);
            ans = max(ans, sum);
        }
        reverse(d.begin(), d.end());
    } 

    cout << ans << '\n';

    return 0;
}
