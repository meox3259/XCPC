#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n;
    cin >> h >> w >> n;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        x[i] --;
        y[i] --;
    }

    vector<vector<int> > low(w);
    for (int i = 0; i < n; ++i) {
        low[y[i]].emplace_back(x[i]);
    }

    for (int i = 0; i < w; ++i) {
        low[i].emplace_back(h);
    }

    for (int i = 0; i < w; ++i) {
        sort(low[i].begin(), low[i].end());
    }

    map<pair<int, int>, bool> mp;
    for (int i = 0; i < n; ++i) {
        mp[{x[i], y[i]}] = true;
    }
    for (int i = 0; i < h; ++i) {
        mp[{i, w}] = true;
    }
    for (int i = 0; i < w; ++i) {
        mp[{h, i}] = true;
    }

    int ans = h;
    int curx = 0;
    int cury = 0;
    int step = 0;
    while (true) {
        ans = min(ans, step + *lower_bound(low[cury].begin(), low[cury].end(), curx) - curx);
        step ++;
        if (mp.find(make_pair(curx + 1, cury)) == mp.end()) {
            curx ++;
        } else {
            ans = min(ans, step);
            break;
        }
        if (mp.find(make_pair(curx, cury + 1)) == mp.end()) {
            cury ++;
        }
    }

    cout << ans << '\n';

    return 0;
}
