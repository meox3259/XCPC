#include <bits/stdc++.h>
using namespace std;
// -std=c++2a
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
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  rmq mn(id, [&] (int i, int j) {
    return a[i] < a[j] ? i : j;
  });
  vector<int> st;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[i] < a[st.back()]) {
      st.pop_back();
    }
    if (st.empty()) {
      l[i] = -1;
    } else {
      l[i] = st.back();
    }
    st.push_back(i);
  }
  st.clear();
  vector<int> r(n);
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && a[i] < a[st.back()]) {
      st.pop_back();
    }
    if (st.empty()) {
      r[i] = n;
    } else {
      r[i] = st.back();
    }
    st.push_back(i);
  }
  vector<long long> pre(n);
  vector<long long> f(n); 
  for (int i = 0; i < n; ++i) {
    f[i] = (l[i] == -1 ? 0 : f[l[i]]) + 1ll * (i - l[i]) * a[i]; 
    pre[i] = (i > 0 ? pre[i - 1] : 0) + f[i];
  }
  vector<long long> suf(n);
  vector<long long> g(n);
  for (int i = n - 1; i >= 0; --i) {
    g[i] = (r[i] == n ? 0 : g[r[i]]) + 1ll * (r[i] - i) * a[i]; 
    suf[i] = (i == n ? 0 : suf[i + 1]) + g[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l --;
    r --;
    int p = mn.query(l, r);
    cout << 1ll * (p - l + 1) * (r - p + 1) * a[p] + pre[r] - pre[p] - f[p] * (r - p) + suf[l] - suf[p] - g[p] * (p - l) << '\n';
  }
}
