#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> n(4);
    for (int i = 0; i < 4; ++i) {
        cin >> n[i];
    }

    vector<vector<int> > a(4);
    for (int i = 0; i < 4; ++i) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int> > up(n[1]);
    vector<vector<int> > mid(n[2]);
    vector<vector<int> > down(n[2]);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        up[y].emplace_back(x);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        mid[y].emplace_back(x);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        down[x].emplace_back(y);
    }

    multiset<int> s;
    for (int i : a[0]) {
        s.emplace(i);
    }

    vector<int> x(n[1], inf);
    vector<int> y(n[2], inf);
    for (int i = 0; i < n[1]; ++i) {
        for (int j : up[i]) {
            s.erase(s.find(a[0][j]));
        }
        if (!s.empty()) {
            x[i] = *s.begin() + a[1][i];
        }
        for (int j : up[i]) {
            s.emplace(a[0][j]);
        }
    }

    s.clear();
    for (int i : a[3]) {
        s.emplace(i);
    }
    for (int i = 0; i < n[2]; ++i) {
        for (int j : down[i]) {
            s.erase(s.find(a[3][j]));
        }
        if (!s.empty()) {
            y[i] = *s.begin() + a[2][i];
        }
        for (int j : down[i]) {
            s.emplace(a[3][j]);
        }
    }

    s.clear();
    for (int i : x) {
        s.emplace(i);
    }
    int ans = inf;
    for (int i = 0; i < n[2]; ++i) {
        for (int j : mid[i]) {
            s.erase(s.find(x[j]));
        }
        if (!s.empty()) {
            ans = min(ans, *s.begin() + y[i]);
        }
        for (int j : mid[i]) {
            s.emplace(x[j]);
        }
    }

    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
