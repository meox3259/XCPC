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
  int T;
  cin >> T;
  while (T --) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      X --;
      Y --;
      adj[X].push_back(Y);
      adj[Y].push_back(X);
    }
    if (N & 1) {
      long long E = 1LL * N * (N - 1) / 2 - M;
      if (E & 1) {
        cout << "First" << '\n';
      } else {
        cout << "Second" << '\n';
      }
    } else {
      dsu dsu(N);
      for (int i = 0; i < N; ++i) {
        for (int j : adj[i]) {
          dsu.unite(i, j);
        }
      }
      int X = dsu.size(0);
      int Y = dsu.size(N - 1);
      long long E = 1LL * N * (N - 1) / 2 - 1LL * X * Y - M;
      if ((X & 1) ^ (Y & 1)) {
        cout << "First" << '\n';
      } else {
        if (E & 1) {
          cout << "First" << '\n';
        } else {
          cout << "Second" << '\n';
        }
      }
    }
  }
  return 0;
}
