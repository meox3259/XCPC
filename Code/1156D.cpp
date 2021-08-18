#include <bits/stdc++.h>
using namespace std;
class dsu {
 private:
  vector<int> dat;
  int components_;
 public:
  dsu() {}
  explicit dsu(int n) : dat(n, -1), components_(n) {}
  int size() {
    return dat.size();
  }
  int root(int x) {
    assert(0 <= x), assert(x < size());
    return dat[x] < 0 ? x : dat[x] = root(dat[x]);
  }
  pair<int, int> unite(int x, int y) {
    assert(0 <= x), assert(x < size());
    assert(0 <= y), assert(y < size());
    x = root(x), y = root(y);
    if (x == y) {
      return { x, -1 };
    }
    components_ --;
    if (-dat[x] < -dat[y]) {
      swap(x, y);
    }
    dat[x] += dat[y];
    dat[y] = x;
    return { x, y };
  }
  bool same(int x, int y) {
    assert(0 <= x), assert(x < size());
    assert(0 <= y), assert(y < size());
    return root(x) == root(y);
  }
  int size(int x) {
    assert(0 <= x), assert(x < size());
    return -dat[root(x)];
  }
  int components() {
    return components_;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  dsu dsu0(n);
  dsu dsu1(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    x --;
    y --;
    if (w == 0) {
      dsu0.unite(x, y);
    } else {
      dsu1.unite(x, y);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu0.root(i) == i) {
      ans += 1ll * dsu0.size(i) * (dsu0.size(i) - 1);
    }
    if (dsu1.root(i) == i) {
      ans += 1ll * dsu1.size(i) * (dsu1.size(i) - 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    ans += 1ll * (dsu0.size(i) - 1) * (dsu1.size(i) - 1);
  }
  cout << ans << '\n';
}
