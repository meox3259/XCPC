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
  vector<double> X(N);
  vector<double> Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }
  vector<int> P(M);
  vector<int> Q(M);
  for (int i = 0; i < M; ++i) {
    cin >> P[i] >> Q[i];
    P[i] --;
    Q[i] --;
  }
  double Ans = 0.;
  auto dis = [&] (int i, int j) -> double {
    return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
  };
  dsu dsu(N);
  vector<tuple<double, int, int>> E;
  for (int i = 0; i < M; ++i) {
    E.emplace_back(dis(P[i], Q[i]), P[i], Q[i]);
  }
  sort(E.begin(), E.end());
  reverse(E.begin(), E.end());
  for (auto [D, X, Y] : E) {
    if (!dsu.same(X, Y)) {
      dsu.unite(X, Y);
    } else {
      Ans += D;
    }
  }
  cout << fixed << setprecision(10);
  cout << Ans << '\n';
}
