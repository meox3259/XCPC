#include <bits/stdc++.h>

using namespace std;

class ConvexHullTrick {
    public:
    using R = long double;
    using lint = long long;
    static constexpr lint max_x = 2000000; // 适当改变
    static constexpr lint inf = numeric_limits<int> :: max();
    class Line {
        public:
        lint a, b = 0;
        R x = 0;
        bool operator < (const Line &r) const {
            return a == inf || r.a == inf ? x < r.x : a < r.a;
        }
    };
    set<Line> se;
    bool need(const Line &l, const Line &m, const Line &r) const {
        return (R)m.b * (r.a - l.a) > (R)l.b * (r.a - m.a) + (R)r.b * (m.a - l.a);
    }
    void add(lint a, lint b) {
        auto itr = se.find({ a });
        if (itr != se.end()) {
            if (b <= itr -> b) {
                return;
            } else {
                itr = se.erase(itr);
            }
        } else {
            itr = se.lower_bound({ a });
            if (itr != se.begin() && itr != se.end() && !need(*prev(itr), { a, b }, *itr)) {
                return;
            }
        }
        if (itr != se.end()) {
            while (next(itr) != se.end() && !need({ a, b }, *itr, *next(itr))) {
                itr = se.erase(itr);
            }
        }
        if (itr != se.begin()) {
            while (prev(itr) != se.begin() && !need(*prev(itr, 2), *prev(itr), { a, b })) {
                se.erase(prev(itr));
            }
        }
        R x = max_x;
        if (itr != se.end()) {
            x = -(R)(itr -> b - b) / (itr -> a - a);
        }
        itr = se.emplace_hint(itr, Line{ a, b, x });
        if (itr != se.begin()) {
            auto e = *prev(itr);
            se.erase(prev(itr));
            e.x = -(R)(b - e.b) / (a - e.a);
            se.insert(e);
        }
    }
    lint max(lint x) const {
        if (se.empty()) {
            return -9e18;
        }
        auto itr =  se.lower_bound({ inf, inf, (R)x });
        return itr -> a * x + itr -> b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<long long> ans(n);
    auto dfs = [&] (auto &&f, int x, int par) -> ConvexHullTrick {
        ConvexHullTrick cur;
        for (int y : adj[x]) {
            if (y != par) {
                auto child = f(f, y, x);
                if (child.se.size() > cur.se.size()) {
                    swap(cur, child);
                }
                for (auto l : child.se) {
                    cur.add(l.a, l.b);
                }
            }
        }
        if (!cur.se.empty()) {
            ans[x] = -cur.max(a[x]);
        }
        cur.add(-b[x], -ans[x]);
        return cur;
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}
