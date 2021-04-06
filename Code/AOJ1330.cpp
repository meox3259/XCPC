#include <bits/stdc++.h>
using namespace std;
class dsu {
  vector<int> par;
  vector<int> val;
 public:
  dsu() {}
  dsu(int N) : par(N), val(N) {
    iota(par.begin(), par.end(), 0);
  }
  int root(int X) {
    if (X == par[X]) {
      return X;
    }
    int P = par[X];
    par[X] = root(par[X]);
    val[X] += val[P];
    return par[X];
  }
  void unite(int X, int Y, int W) {
    int FX = root(X);
    int FY = root(Y);
    if (FX == FY) {
      return;
    }
    val[FY] = val[X] + W - val[Y];
    par[FY] = FX;
  }
  void ask(int X, int Y) {
    if (root(X) != root(Y)) {
      cout << "UNKNOWN" << '\n';
    } else {
      cout << val[X] - val[Y] << '\n'; 
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  while (cin >> N >> M) {
    if (N == 0 && M == 0) {
      break;
    }
    dsu dsu(N);
    for (int i = 0; i < M; ++i) {
      char opt;
      cin >> opt;
      if (opt == '!') {
        int X, Y, W;
        cin >> X >> Y >> W;
        X --;
        Y --;
        dsu.unite(Y, X, W);
      } else {
        int X, Y;
        cin >> X >> Y;
        X --;
        Y --;
        dsu.ask(X, Y);
      }
    }
  }
}
