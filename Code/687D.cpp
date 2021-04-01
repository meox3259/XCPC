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
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<tuple<int, int, int, int>> E;
  for (int i = 0; i < M; ++i) {
    int X, Y, W;
    cin >> X >> Y >> W;
    X --;
    Y --;
    E.emplace_back(W, X, Y, i);
  }
  sort(E.begin(), E.end(), greater<tuple<int, int, int, int>> ());
  while (Q --> 0) {
    int L, R;
    cin >> L >> R;
    L --;
    R --;
    dsu dsu(N * 2);
    int Ans = -1;
    for (auto [W, X, Y, i] : E) {
      if (L <= i && i <= R) {
        if (dsu.same(X * 2, Y * 2)) {
          Ans = W;
          break;
        }
        dsu.unite(X * 2, Y * 2 + 1);
        dsu.unite(X * 2 + 1, Y * 2);
      } 
    }
    cout << Ans << '\n';
  }
}
