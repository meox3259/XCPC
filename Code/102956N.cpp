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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  rmq rmq(id, [&] (int i, int j) {
    return a[i] > a[j] ? i : j;
  });
  vector<int> ans;
  auto dfs = [&] (auto &&f, int l, int r, int v) -> void {
    if (l > r) {
      return;
    }
    int p = rmq.query(l, r);
    if (a[p] + r - l < v) {
      return;
    }
    ans.push_back(p);
    f(f, l, p - 1, max(v + p - r - 1, a[p]));
    f(f, p + 1, r, max(v + l - p - 1, a[p]));
  };
  dfs(dfs, 0, n - 1, -1);
  sort(ans.begin(), ans.end());
  int k = ans.size();
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << ans[i] + 1 << " \n"[i == k - 1];
  }
}
