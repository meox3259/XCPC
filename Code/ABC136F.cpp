#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
const int inf = 1000000000 + 7;

class SegmentTree {
    vector<int> lc;
    vector<int> rc;
    vector<int> sum;
    int Pool;
    public:
    SegmentTree(int n) : Pool(0), sum(n * 60), lc(n * 60), rc(n * 60) {}

    void update(int l, int r, int &x, int p, int v) {
        if (x == 0) {
            x = ++Pool;
        }
        sum[x] += v;
        if (l == r) {
            return;
        }
        int mid = l + r >> 1;
        if (p <= mid) {
            update(l, mid, lc[x], p, v);
        } else {
            update(mid + 1, r, rc[x], p, v); 
        }
    }

    int query(int l, int r, int x, int a, int b) {
        if (l > b || r < a || x == 0) {
            return 0;
        }
        if (l >= a && r <= b) {
            return sum[x];
        }
        int mid = l + r >> 1;
        return query(l, mid, lc[x], a, b) + query(mid + 1, r, rc[x], a, b);
    }
};

long long power(long long x, long long t) {
    long long ret = 1;
    for (; t; t >>= 1, x = x * x % P) {
        if (t & 1) {
            ret = ret * x % P;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());

    SegmentTree seg(n);
    vector<int> a(n);
    vector<int> b(n);
    int root = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = seg.query(-inf, inf, root, -inf, p[i].second - 1);
        b[i] = seg.query(-inf, inf, root, p[i].second + 1, inf);
        seg.update(-inf, inf, root, p[i].second, 1);
    }

    SegmentTree rev(n);
    vector<int> c(n);
    vector<int> d(n);
    root = 0;
    for (int i = n - 1; i >= 0; --i) {
        c[i] = rev.query(-inf, inf, root, p[i].second + 1, inf);
        d[i] = rev.query(-inf, inf, root, -inf, p[i].second - 1);
        rev.update(-inf, inf, root, p[i].second, 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long A = power(2, a[i]);
        long long B = power(2, b[i]);
        long long C = power(2, c[i]);
        long long D = power(2, d[i]);
        ans += (A - 1 + P) % P * (C - 1 + P) % P * B % P * D % P;
        ans += (B - 1 + P) % P * (D - 1 + P) % P * A % P * C % P;
        ans -= (A - 1 + P) % P * (B - 1 + P) % P * (C - 1 + P) % P * (D - 1 + P) % P; 
        ans += A * B % P * C % P * D % P;
        ans += P;
        ans %= P;
    }

    cout << ans << '\n';

    return 0;
}
