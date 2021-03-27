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
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<tuple<int, int, int>> E;
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    E.emplace_back(min(A[X], A[Y]), X, Y);
  }
  sort(E.begin(), E.end(), [&] (auto X, auto Y) {
    return get<0>(X) > get<0>(Y);
  });
  dsu dsu(N);
  long double Ans = 0;
  for (auto [W, X, Y] : E) {
    if (!dsu.same(X, Y)) {
      Ans += 1. * dsu.size(X) * dsu.size(Y) * W; 
      dsu.unite(X, Y);
    }
  }
  Ans /= (1. * N * (N - 1) / 2.);
  cout << fixed << setprecision(15);
  cout << Ans << '\n';
}
