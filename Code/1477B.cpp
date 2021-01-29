#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<int> c;
    vector<vector<int> > sum;
    vector<int> cover;
    public:
    SegmentTree() {}
    SegmentTree(int N) : cover(N * 4 + 5), c(N * 4 + 5), sum(N * 4 + 5, vector<int> (2)) {}

    void pushdown(int x, int l, int r) {
        if (cover[x] != -1) {
            int o = cover[x];
            int mid = l + r >> 1;
            cover[x << 1] = o;
            cover[x << 1 | 1] = o;
            sum[x << 1][o] = mid - l + 1;
            sum[x << 1 | 1][o] = r - mid;
            sum[x << 1][o ^ 1] = 0;
            sum[x << 1 | 1][o ^ 1] = 0;
            cover[x] = -1;
        }
    }
    void update(int l, int r, int x, int a, int b, int v) {
        if (l > b || r < a) {
            return;
        }
        if (l >= a && r <= b) {
            cover[x] = v; 
            sum[x][v] = r - l + 1;
            sum[x][v ^ 1] = 0;
            return;
        }
        int mid = l + r >> 1;
        pushdown(x, l, r);
        update(l, mid, x << 1, a, b, v);
        update(mid + 1, r, x << 1 | 1, a, b, v);
        sum[x][0] = sum[x << 1][0] + sum[x << 1 | 1][0];
        sum[x][1] = sum[x << 1][1] + sum[x << 1 | 1][1];
    }

    int query(int l, int r, int x, int a, int b) {
        if (l > b || r < a) {
            return 0;
        }
        if (l >= a && r <= b) {
            return sum[x][0];
        }
        pushdown(x, l, r);
        int mid = l + r >> 1;
        return query(l, mid, x << 1, a, b) + query(mid + 1, r, x << 1 | 1, a, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T --) {
        int n, q;
        cin >> n >> q;

        string s, t;
        cin >> s >> t;
        
        vector<int> l(q);
        vector<int> r(q);
        for (int i = q - 1; i >= 0; --i) {
            cin >> l[i] >> r[i];
            l[i] --;
            r[i] --;
        }

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
        }

        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = t[i] - '0';
        }

        SegmentTree seg(n);
        for (int i = 0; i < n; ++i) {
            seg.update(0, n - 1, 1, i, i, b[i]);
        }
        bool ok = true;
        for (int i = 0; i < q; ++i) {
            int tot = seg.query(0, n - 1, 1, l[i], r[i]);   
            int len = r[i] - l[i] + 1;
            int zero = seg.query(0, n - 1, 1, l[i], r[i]);
            if (zero + zero == len) {
                ok = false;
                break;
            }
            if (zero + zero < len) {
                seg.update(0, n - 1, 1, l[i], r[i], 1);
            } else {
                seg.update(0, n - 1, 1, l[i], r[i], 0);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (seg.query(0, n - 1, 1, i, i) != (a[i] ^ 1)) {
                ok = false;
            }
        }

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
