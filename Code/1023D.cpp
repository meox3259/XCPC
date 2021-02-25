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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] --;
    }

    FenwickTree<int> fw(n);

    vector<vector<int> > p(q);
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            p[a[i]].emplace_back(i);
        }
    }

    bool ok = true;
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j + 1 < p[i].size(); ++j) {
            if (fw.query(p[i][j + 1]) - fw.query(p[i][j]) > 0) {
                ok = false;
            }
        }
        for (int j : p[i]) {
            fw.add(j, 1);
        }
    }

    if (!ok) {
        cout << "NO" << '\n';
        exit(0);
    }

    if (*max_element(a.begin(), a.end()) == -1) {
        cout << "YES" << '\n'; 
        for (int i = 0; i < n; ++i) {
            cout << q << " \n"[i == n - 1];
        }
        exit(0);
    }

    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (a[i] != -1) {
            pos.emplace_back(i);
        }
    }

    int o = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            auto it = lower_bound(pos.begin(), pos.end(), i);
            if (it == pos.end()) {
                it = prev(it);
            }
            a[i] = a[*it];
            o = i;
        }
    }

    if (o != -1 && *max_element(a.begin(), a.end()) < q - 1) {
        a[o] = q - 1;
    }

    if (*max_element(a.begin(), a.end()) < q - 1) {
        cout << "NO" << '\n';
        exit(0);
    }

    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}
