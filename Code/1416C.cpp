#include <bits/stdc++.h>

using namespace std;

template <class T> 
class FenwickTree {
    int N;
    vector<T> v;

    public:
    FenwickTree(int N) : N(N), v(N) {}

    void add(int p, T val) {
        for(int i = p + 1; i <= N; i += (i & -i)) {
            v[i - 1] += val;
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p + 1; i >= 1; i -= (i & -i)) {
            sum += v[i - 1];
        }
        return sum;
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

    auto calc = [&] (vector<int> a) -> long long {
        vector<pair<int, int> > p;
        for (int i = 0; i < n; ++i) {
            p.emplace_back(a[i], i);
        }
        sort(p.begin(), p.end());
        FenwickTree<int> fw(n);
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += i - fw.query(p[i].second);
            fw.add(p[i].second, 1);
        }
        return ret;
    };

    int x = 0;
    long long last = calc(a);

    for (int b = 30; b >= 0; --b) {
        vector<int> tmp(a);
        for (int i = 0; i < n; ++i) {
            tmp[i] ^= 1 << b;
        }
        long long cur = calc(tmp);
        if (cur < last) {
            swap(a, tmp);
            x ^= 1 << b;
            last = cur;
        }
    }

    cout << last << ' ' << x << '\n';

    return 0;
}
