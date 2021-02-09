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
            v[i - 1] = max(v[i - 1], val);
        }
    }

    T query(int p) {
        T sum = 0;
        for(int i = p + 1; i >= 1; i -= (i & -i)) {
            sum = max(sum, v[i - 1]);
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
        a[i] --;
    }

    vector<int> old(n);
    for (int i : a) {
        old[i] ++;
    }

    vector<vector<int> > pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i]].emplace_back(i);
    }

    int back = a.back();
    while (!a.empty() && a.back() == back) {
        a.pop_back();
    }

    vector<int> cnt(n);
    for (int i : a) {
        cnt[i] ++;
    }

    vector<tuple<int, int, int> > seg;
    for (int i = 0; i < n; ++i) {
        if (!pos[i].empty()) {
            seg.emplace_back(pos[i].back(), pos[i][0], cnt[i]);
        }
    }

    sort(seg.begin(), seg.end());

    FenwickTree<int> fw(n); 
    int Max = 0;
    int ans = n;
    for (auto [r, l, sz] : seg) {
        int cur = fw.query(l - 1) + sz; 
        ans = min(ans, (int)a.size() - cur);
        fw.add(r, cur);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
            ans = min(ans, n - fw.query(pos[i][j] - 1) - old[i] + j);
        }
    }

    cout << ans << '\n';

    return 0;
}
