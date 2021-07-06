#include<bits/stdc++.h>
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
  int N, M, V;
  cin >> N >> M >> V;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    adj[X].emplace_back(Y, i);
    adj[Y].emplace_back(X, i);
  }
  if (accumulate(A.begin(), A.end(), 0LL) < 1LL * (N - 1) * V) {
    cout << "NO" << '\n';
    exit(0);
  } 
  set<pair<long long, int>> S;
  for (int i = 0; i < N; ++i) {
    S.emplace(A[i], i);
  }
  dsu dsu(N);
  vector<int> Ans;
  for (int i = 0; i < N - 1; ++i) {
    int X = S.rbegin() -> second; 
    while (dsu.same(adj[X].back().first, X)) {
      adj[X].pop_back();
    }
    int Y = dsu.root(adj[X].back().first); 
    Ans.push_back(adj[X].back().second);
    adj[X].pop_back();
    if (dsu.size(X) < dsu.size(Y)) {
      swap(X, Y);
    }
    dsu.unite(X, Y);
    while (!adj[Y].empty()) {
      adj[X].push_back(adj[Y].back());
      adj[Y].pop_back();
    }
    S.erase(S.find(make_pair(A[X], X)));
    S.erase(S.find(make_pair(A[Y], Y)));
    A[X] = A[X] + A[Y] - V;
    S.emplace(A[X], X);
  }   
  cout << "YES" << '\n';
  for (int i : Ans) {
    cout << i + 1 << '\n';
  }
}
