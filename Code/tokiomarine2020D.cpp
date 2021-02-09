#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> w[i];
    }

    vector<int> bit(1 << 18);
    for (int i = 0; i < 18; ++i) {
        bit[1 << i] = i;
    }

    int q;
    cin >> q;

    auto lowbit = [&] (int x) -> int {
        return x & (-x);
    };

    vector<vector<pair<int, int> > > rem(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        vector<pair<int, int> > obj;
        while (x != 0) {
            obj.emplace_back(w[x - 1], v[x - 1]);
            x /= 2;
        }
        if (obj.size() <= 10) {
            vector<pair<int, int> > f(1 << obj.size());
            for (int S = 1; S < 1 << obj.size(); ++S) {
                f[S] = { f[S ^ lowbit(S)].first + obj[bit[lowbit(S)]].first, f[S ^ lowbit(S)].second + obj[bit[lowbit(S)]].second };
            }
            sort(f.begin(), f.end());
            for (int i = 0; i + 1 < f.size(); ++i) {
                f[i + 1].second = max(f[i + 1].second, f[i].second);
            }
            rem[i] = f;
        }
    }

    while (q --) {
        int x, L;
        cin >> x >> L;

        vector<pair<int, int> > obj;
        while (x != 0) {
            if (!rem[x].empty()) {
                break;
            }
            obj.emplace_back(w[x - 1], v[x - 1]);
            x /= 2;
        }

        int m = obj.size();

        vector<pair<int, int> > f = rem[x];
        vector<pair<int, int> > g(1 << obj.size());
        for (int S = 1; S < 1 << obj.size(); ++S) {
            g[S] = { g[S ^ lowbit(S)].first + obj[bit[lowbit(S)]].first, g[S ^ lowbit(S)].second + obj[bit[lowbit(S)]].second };
        }

        sort(g.begin(), g.end());
        for (int i = 0; i + 1 < g.size(); ++i) {
            g[i + 1].second = max(g[i + 1].second, g[i].second);
        }

        int ans = 0;
        for (int i = 0; i < g.size(); ++i) {
            if (g[i].first > L) {
                break;
            }
            auto it = lower_bound(f.begin(), f.end(), make_pair(L - g[i].first + 1, -1)); 
            if (it != g.begin()) {
                ans = max(ans, g[i].second + prev(it) -> second);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
