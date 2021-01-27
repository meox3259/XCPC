#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int> :: max() / 2;

class SegmentTree {
    vector<int> mn;

    public:
    SegmentTree() {}
    SegmentTree(int N) : mn(N * 4 + 5, inf) {}

    void update(int l, int r, int x, int a, int b, int v) {
        if (l > b || r < a) {
            return;
        }
        if (l >= a && r <= b) {
            mn[x] = min(mn[x], v);
            return;
        }
        int mid = l + r >> 1;
        update(l, mid, x << 1, a, b, v);
        update(mid + 1, r, x << 1 | 1, a, b, v);
    }

    int query(int l, int r, int x, int p) {
        if (l == r) {
            return mn[x];
        }
        int mid = l + r >> 1;
        if (p <= mid) {
            return min(mn[x], query(l, mid, x << 1, p)); 
        } else {
            return min(mn[x], query(mid + 1, r, x << 1 | 1, p));
        }
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
        a[i] --;
    }

    vector<vector<int> > p(n);
    for (int i = 0; i < n; ++i) {
        p[a[i]].emplace_back(i);
    }

    if (*max_element(a.begin(), a.end()) == 0) {
        cout << 1 << '\n';
        exit(0);
    }

    SegmentTree seg(n);
    for (int i = 0; i < n; ++i) {
        if (!p[i].empty()) {
            seg.update(0, n - 1, 1, 0, p[i][0] - 1, -inf);
            for (int j = 0; j < p[i].size(); ++j) {
                seg.update(0, n - 1, 1, p[i][j], (j == (int)p[i].size() - 1 ? n - 1 : p[i][j + 1] - 1), p[i][j]);
            }
            bool ok = false;
            if (i != n - 1 && !p[i + 1].empty()) {
                for (int j = 0; j < p[i + 1].size(); ++j) {
                    int pre = (j == 0 ? -1 : p[i + 1][j - 1]);
                    if (seg.query(0, n - 1, 1, p[i + 1][j] - 1) > pre) {
                        ok = true;
                    }
                }
                if (seg.query(0, n - 1, 1, n - 1) > p[i + 1].back()) {
                    ok = true;
                }
            } else {
                if (seg.query(0, n - 1, 1, n - 1) >= 0) {
                    ok = true;
                }
            }
            if (!ok) {
                cout << i + 2 << '\n';
                exit(0);
            }
        } else {
            cout << i + 2 << '\n';
            exit(0);
        }
    }

    cout << n + 2 << '\n';

	return 0;
}
