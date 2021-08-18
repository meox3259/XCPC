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
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu dsu0(n);
  dsu dsu1(n);
  vector<set<int>> s0(n);
  for (int i = 0; i < m1; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    dsu0.unite(x, y);
  }
  for (int i = 0; i < m2; ++i) {
    int x, y;
    cin >> x >> y;
    x --;
    y --;
    dsu1.unite(x, y);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < n; ++i) {
    if (!dsu0.same(0, i) && !dsu1.same(0, i)) {
      ans.emplace_back(0, i);
      dsu0.unite(0, i);
      dsu1.unite(0, i);
    }
  }
  set<int> w0;
  for (int i = 0; i < n; ++i) {
    if (!dsu0.same(0, i)) {
      w0.insert(i);
    }
  }
  set<int> w1;
  for (int i = 0; i < n; ++i) {
    if (!dsu1.same(0, i)) {
      w1.insert(i);
    }
  }
  while (!w0.empty() && !w1.empty()) {
    while (!w0.empty()) {
      int x = *w0.begin();
      if (dsu0.same(0, x) && dsu1.same(0, x)) {
        w0.erase(w0.begin());
      } else {
        break;
      }
    }
    while (!w1.empty()) {
      int x = *w1.begin();
      if (dsu0.same(0, x) && dsu1.same(0, x)) {
        w1.erase(w1.begin());
      } else {
        break;
      }
    }
    if (w0.empty() || w1.empty()) {
      break;
    }
    int x = *w0.begin();
    int y = *w1.begin();
    if (!dsu0.same(x, y) && !dsu1.same(x, y)) {
      dsu0.unite(x, y);
      dsu1.unite(x, y);
      ans.emplace_back(x, y);
    }
    w0.erase(w0.begin());
    w1.erase(w1.begin());
  }
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}
