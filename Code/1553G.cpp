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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int M = *max_element(A.begin(), A.end()) + 1;
  vector<bool> mark(M + 1);
  vector<int> lp(M + 1, -1);
  for (int i = 2; i <= M; ++i) {
    if (!mark[i]) {
      for (int j = i; j <= M; j += i) {
        if (lp[j] == -1) {
          lp[j] = i;
        }
      }
    }
  }
  dsu dsu(N + M + 1);
  for (int i = 0; i < N; ++i) {
    int V = A[i];
    while (V != 1) {
      dsu.unite(lp[V] + N, i);
      V /= lp[V];
    }
  }
  set<pair<int, int>> E;
  for (int i = 0; i < N; ++i) {
    int V = A[i] + 1;
    vector<int> fac;
    while (V != 1) {
      fac.push_back(lp[V]);
      V /= lp[V];
    }
    V = A[i];
    while (V != 1) {
      fac.push_back(lp[V]);
      V /= lp[V];
    }
    sort(fac.begin(), fac.end());
    fac.erase(unique(fac.begin(), fac.end()), fac.end());
    for (int X : fac) {
      for (int Y : fac) {
        if (X != Y) {
          E.emplace(dsu.root(X + N), dsu.root(Y + N));
        }
      }
    }
  }
  while (Q --> 0) {
    int S, T;
    cin >> S >> T;
    S --;
    T --;
    if (dsu.same(S, T)) {
      cout << 0 << '\n';
    } else if ((A[S] & 1) ^ (A[T] & 1)) {
      cout << 1 << '\n';
    } else {
      if (E.find({dsu.root(S), dsu.root(T)}) != E.end()) {
        cout << 1 << '\n';
      } else {
        cout << 2 << '\n'; 
      }
    }
  }
}
