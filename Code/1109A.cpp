#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] ^ a[i];
    }

    vector<vector<int> > cnt(2, vector<int> (1 << 20));
    cnt[0][0] ++;
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += cnt[i & 1][pre[i]];
        cnt[i & 1][pre[i]] ++;
    }

    cout << ans << '\n';

    return 0; 
}
