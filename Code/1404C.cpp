#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<int> sum;
    vector<int> lc;
    vector<int> rc;
    int Pool;

    public:
    SegmentTree() {}
    SegmentTree(int n) : sum(n * 60), lc(n * 60), rc(n * 60) { 
        Pool = 0;
    }

    void update(int l, int r, int &x, int last, int p, int v) {
        x = ++Pool;
        sum[x] = sum[last] + v;
        lc[x] = lc[last];
        rc[x] = rc[last];
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid) {
            update(l, mid, lc[x], lc[last], p, v);
        } else {
            update(mid + 1, r, rc[x], rc[last], p, v);
        }
    }

    int QuerySum(int l, int r, int x, int a, int b) {
        if (l > b || r < a || x == 0) {
            return 0;
        }
        if (l >= a && r <= b) {
            return sum[x];
        }
        int mid = l + r >> 1;
        return QuerySum(l, mid, lc[x], a, b) + QuerySum(mid + 1, r, rc[x], a, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] --;
    }

    SegmentTree seg(n);
    vector<int> root(n + 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) {
            seg.update(1, n, root[i + 1], root[i], i + 1, 1); 
        } else if (i - a[i] > 0) {
            int l = -1;
            int r = i;
            while (r - l > 1) {
                int mid = l + r >> 1;
                int tot = seg.QuerySum(1, n, root[i], mid + 1, n);
                if (tot >= i - a[i]) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (l != -1) {
                seg.update(1, n, root[i + 1], root[i], l + 1, 1);
            } else {
                root[i + 1] = root[i];
            }
        } else {
            root[i + 1] = root[i]; 
        }
    }

    while (q --) {
        int x, y;
        cin >> x >> y;
        cout << seg.QuerySum(1, n, root[n - y], x + 1, n - y) << '\n';
    }

    return 0;
}
