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
  vector<string> S(N);
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }
  dsu dsu(N + M);
  vector<pair<int, int>> node;
  vector<vector<int>> id(N, vector<int> (M, -1));
  int K = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (S[i][j] == 'R' && !dsu.same(i, j + N)) {
        dsu.unite(i, j + N); 
        node.emplace_back(i, j);
        id[i][j] = K ++;
      } 
    }
  }
  vector<vector<int>> adj(K);
  for (int i = 0; i < N; ++i) {
    int last = -1;
    for (int j = 0; j < M; ++j) {
      if (id[i][j] != -1) {
        if (last != -1) {
          adj[last].push_back(id[i][j]);
          adj[id[i][j]].push_back(last);
        }
        last = id[i][j];
      } 
    }
  }
  for (int j = 0; j < M; ++j) {
    int last = -1;
    for (int i = 0; i < N; ++i) {
      if (id[i][j] != -1) {
        if (last != -1) {
          adj[last].push_back(id[i][j]);
          adj[id[i][j]].push_back(last);
        }
        last = id[i][j];
      }
    }
  }
  int row = N;
  int col = M;
  vector<tuple<char, int, int>> Ans;
  vector<bool> vis(K);
  int cr = 0;
  int cl = 0;
  auto dfs = [&] (auto &&f, int X, int F) -> void {
    vis[X] = true;
    for (int Y : adj[X]) {
      if (Y != F) {
        f(f, Y, X);
      }
    }
    if (F != -1) {
      if (node[X].first == node[F].first) {
        Ans.emplace_back('Y', node[X].first, node[X].second);
        col --;
        cl ++;
      } else {
        Ans.emplace_back('X', node[X].first, node[X].second);
        row --;
        cr ++;
      }
    }
  };
  vector<int> wait;
  for (int i = 0; i < K; ++i) {
    if (!vis[i]) {
      dfs(dfs, i, -1);
      wait.push_back(i);
    }
  }
  int Max = 0; 
  int SZ = wait.size();
  for (int i = 0; i <= SZ; ++i) {
    Max = max(Max, -(cl + i) * (cr + SZ - i) + (cl + i) * N + (cr + SZ - i) * M); 
  }
  for (int i = 0; i <= SZ; ++i) {
    if (Max == -(cl + i) * (cr + SZ - i) + (cl + i) * N + (cr + SZ - i) * M) {
      for (int j = 0; j < i; ++j) {
        Ans.emplace_back('Y', node[wait.back()].first, node[wait.back()].second);
        wait.pop_back();
      } 
      for (int j = 0; j < SZ - i; ++j) {
        Ans.emplace_back('X', node[wait.back()].first, node[wait.back()].second);
        wait.pop_back();
      }
      break;
    }
  }
  cout << Ans.size() << '\n';
  for (auto [dir, X, Y] : Ans) {
    cout << dir << ' ' << X + 1 << ' ' << Y + 1 << '\n';
  }
}
