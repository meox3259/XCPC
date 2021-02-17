#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<long long> sum;
    vector<long long> tag;
    vector<long long> Min;
    public:
    SegmentTree() {}
    SegmentTree(int N) : sum(N * 4), tag(N * 4), Min(N * 4) {}
    void pushdown(int x, int l, int r) {
        if (tag[x] != 0) {
            int mid = l + r >> 1;
            tag[x << 1] = tag[x];
            tag[x << 1 | 1] = tag[x];
            sum[x << 1] = 1LL * (mid - l + 1) * tag[x];
            sum[x << 1 | 1] = 1LL * (r - mid) * tag[x];
            Min[x << 1] = tag[x];
            Min[x << 1 | 1] = tag[x];
            tag[x] = 0;
        }
    }
    int pre(int l, int r, int x, int v) {
        if (l == r) {
            if (sum[x] > v) {
                return -1;
            } else {
                return l;
            }
        } 
        pushdown(x, l, r);
        int mid = l + r >> 1;
        if (Min[x << 1] > v) {
            return pre(mid + 1, r, x << 1 | 1, v);
        } else {
            return pre(l, mid, x << 1, v);
        }
    }
    void update(int l, int r, int x, int a, int b, long long v) {
        if (l > b || r < a) {
            return;
        } 
        if (l >= a && r <= b) {
            tag[x] = v;
            sum[x] = 1LL * (r - l + 1) * v;
            Min[x] = v;
            return;
        }
        pushdown(x, l, r);
        int mid = l + r >> 1;
        update(l, mid, x << 1, a, b, v);
        update(mid + 1, r, x << 1 | 1, a, b, v);
        Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
        sum[x] = sum[x << 1] + sum[x << 1 | 1];
    }
    long long query(int l, int r, int x, int s, long long &v) {
        if (r < s || Min[x] > v) {
            return 0;
        }
        if (l >= s) {
            if (sum[x] <= v) {
                v -= sum[x];
                return r - l + 1;
            } 
        }
        pushdown(x, l, r);
        int mid = l + r >> 1;
        return query(l, mid, x << 1, s, v) + query(mid + 1, r, x << 1 | 1, s, v);
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
    }

    SegmentTree seg(n);
    for (int i = 0; i < n; ++i) {
        seg.update(0, n - 1, 1, i, i, a[i]);
    }

    while (q --) {
        int t, x;
        long long y;
        cin >> t >> x >> y;
        x --;

        if (t == 1) {
            int p = seg.pre(0, n - 1, 1, y); 
            if (p != -1) {
                seg.update(0, n - 1, 1, p, x, y);
            }
        }

        if (t == 2) {
            cout << seg.query(0, n - 1, 1, x, y) << '\n';
        }
    }

    return 0;
}
