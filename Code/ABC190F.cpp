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

    vector<int> b(n + n);
    for (int i = 0; i < n; ++i) {
        b[i] = b[i + n] = a[i];
    }

    FenwickTree<int> fw(n);
    vector<long long> ans(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i - fw.query(a[i]);
        fw.add(a[i], 1);
    }

    ans[0] = sum;
    for (int i = 0; i < n - 1; ++i) {
        sum -= a[i];
        sum += n - a[i] - 1;
        ans[i + 1] = sum;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
