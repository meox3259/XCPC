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
  vector<tuple<int, int, int>> E;
  vector<map<int, bool>> mp(N);
  int S = 0;
  for (int i = 0; i < M; ++i) {
    int X, Y, W;
    cin >> X >> Y >> W;
    X --;
    Y --;
    mp[X][Y] = true;
    mp[Y][X] = true;
    S ^= W;
    E.emplace_back(W, X, Y);
  }
  if (1LL * N * (N - 1) / 2 - M > N) {
    dsu dsu(N);
    vector<bool> vis(N);
    vector<int> V;
    for (int i = 0; i < N; ++i) {
      V.push_back(i);
    }
    while (!V.empty()) {
      int P = V.back();
      V.pop_back();
      queue<int> Q;
      Q.push(P);
      while (!Q.empty()) {
        int X = Q.front();
        Q.pop();
        for (int i = 0; i < (int)V.size(); ++i) {
          int Y = V[i];
          if (mp[X].count(Y) == 0) {
            dsu.unite(V[i], P);
            swap(V[i], V.back());
            V.pop_back();
            i --;
            Q.push(Y);
          }
        }
      }
    }
    long long Ans = 0;
    sort(E.begin(), E.end());
    for (auto [W, X, Y] : E) {
      if (!dsu.same(X, Y)) {
        Ans += W;
        dsu.unite(X, Y);
      }
    }
    cout << Ans << '\n';
    exit(0);
  }
  sort(E.begin(), E.end());
  vector<vector<bool>> vis(N, vector<bool> (N, true));
  for (auto [W, X, Y] : E) {
    vis[X][Y] = vis[Y][X] = false;
  }
  vector<pair<int, int>> zero;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (vis[i][j]) {
        zero.emplace_back(i, j);
      }
    }
  }
  long long Ans = numeric_limits<long long> :: max();
  for (int i = 0; i < zero.size(); ++i) {
    dsu dsu(N);
    for (int j = 0; j < zero.size(); ++j) {
      if (i != j) {
        dsu.unite(zero[j].first, zero[j].second);
      }
    }
    long long tmp = 0;
    bool used = false;
    for (auto [W, X, Y] : E) {
      if (!used && W >= S) {
        used = true;
        if (!dsu.same(zero[i].first, zero[i].second)) {
          tmp += S;
          dsu.unite(zero[i].first, zero[i].second);
        }
      }
      if (!dsu.same(X, Y)) {
        tmp += W;
        dsu.unite(X, Y);
      }
    }
    if (!used) {
      if (!dsu.same(zero[i].first, zero[i].second)) {
        tmp += S;
      }
    }
    Ans = min(Ans, tmp);
  }
  cout << Ans << '\n';
}
