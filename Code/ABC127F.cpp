#include <bits/stdc++.h>

using namespace std;

const int m = 1000000000;

class SegmentTree {
    vector<long long> sum;
    vector<int> sz;
    vector<int> lc;
    vector<int> rc;
    int Pool;

    public:
    SegmentTree() {}
    SegmentTree(int n) : sum(n * 60), sz(n * 60), lc(n * 60), rc(n * 60) { 
        Pool = 0;
    }

    void update(int l, int r, int &x, int p) {
        if (x == 0) {
            x = ++Pool;
        }
        sz[x] ++;
        sum[x] += p;
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid) {
            update(l, mid, lc[x], p);
        } else {
            update(mid + 1, r, rc[x], p);
        }
    }

    int kth(int l, int r, int x, int k) {
        if (l == r) {
            return l;
        }
        int mid = l + r >> 1;
        if (sz[lc[x]] >= k) {
            return kth(l, mid, lc[x], k);
        } else {
            return kth(mid + 1, r, rc[x], k - sz[lc[x]]);
        }
    }

    long long query(int l, int r, int x, int k) {
        if (l == r) {
            return 1LL * l * k;
        }
        int mid = l + r >> 1;
        if (sz[lc[x]] >= k) {
            return query(l, mid, lc[x], k);
        } else {
            return query(mid + 1, r, rc[x], k - sz[lc[x]]) + sum[lc[x]];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    int n = 0;
    int root = 0;
    long long sum = 0;
    SegmentTree seg(q);

    while (q --) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            seg.update(-m, m, root, a);
            sum += b;
            n ++;
        }

        if (type == 2) {
            int x = seg.kth(-m, m, root, (n + 1) / 2); 
            long long pre = seg.query(-m, m, root, (n + 1) / 2);
            long long suf = seg.query(-m, m, root, n) - pre;
            int half = (n + 1) / 2;
            cout << x << ' ' << suf - 1LL * (n - half) * x + 1LL * half * x - pre + sum << '\n';
        }
    }

    return 0;
}
