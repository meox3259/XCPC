#include <bits/stdc++.h>

using namespace std;

const long long inf = numeric_limits<long long> :: max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; 
    }

    vector<bool> cover(n);
    long long Min = inf;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] - b[i] > 0) {
            Min = min(Min, a[i] - b[i]);
        } else {
            if (a[i] >= Min) {
                cover[i] = true;
            }
        }
    }

    long long ans = inf; 
    long long tot = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] - b[i] <= 0) {
            long long d = b[i] - a[i] + 1;
            ans = min(ans, d + max(0LL, tot - d)); 
            if (!cover[i]) {
                tot ++;
            }
        }
    }

    ans = min(ans, tot);

    cout << ans << '\n';

    return 0;
}
