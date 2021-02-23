#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> pre(m);
    vector<int> suf(m);

    vector<vector<int> > p(26);
    for (int i = 0; i < n; ++i) {
        p[s[i] - 'a'].emplace_back(i);
    }

    int cur = -1;
    for (int i = 0; i < m; ++i) {
        int c = t[i] - 'a';
        cur = *upper_bound(p[c].begin(), p[c].end(), cur);
        pre[i] = cur;
    }

    cur = n;
    for (int i = m - 1; i >= 0; --i) {
        int c = t[i] - 'a';
        cur = *prev(lower_bound(p[c].begin(), p[c].end(), cur));
        suf[i] = cur;
    }

    int ans = 0;
    for (int i = 0; i < m - 1; ++i) {
        ans = max(ans, suf[i + 1] - pre[i]);
    }

    cout << ans << '\n';

    return 0;
}
