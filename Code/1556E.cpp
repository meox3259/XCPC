#include <bits/stdc++.h>
using namespace std;
template<typename T, class F> class rmq {
  vector<vector<T>> b;
  F f;
 public:
  rmq(vector<T> v, F _f) : f(_f) {
    int n = v.size();
    int m = 32 - __builtin_clz(n);
    b = vector<vector<T>> (n, vector<T> (m));
    for (int i = 0; i < n; ++i) {
      b[i][0] = v[i];
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n - (1 << j) + 1; ++i) {
        b[i][j] = f(b[i][j - 1], b[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T query(int l, int r) {
    int x = floor(log2(r - l + 1));
    return f(b[l][x], b[r - (1 << x) + 1][x]);
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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> pre(n);
  pre[0] = a[0] - b[0];
  for (int i = 0; i < n - 1; ++i) {
    pre[i + 1] = pre[i] + a[i + 1] - b[i + 1];
  }
  rmq mx(pre, [&] (long long i, long long j) {
    return max(i, j);
  });
  rmq mn(pre, [&] (long long i, long long j) {
    return min(i, j);
  });
  while (q--) {
    int l, r;
    cin >> l >> r;
    l --;
    r --;
    long long minus = (l > 0 ? pre[l - 1] : 0);
    long long x = mx.query(l, r);
    long long y = mn.query(l, r);
    if (x - minus >= 1 || pre[r] != minus) {
      cout << -1 << '\n';
    } else {
      cout << minus - y << '\n';
    }
  }
}
