#include <bits/stdc++.h>
using namespace std;
template <class T> 
class FenwickTree {
  int N;
  vector<T> v;
 public:
  FenwickTree(int N) : N(N), v(N) {}
  void add(int p, T val) {
    for(int i = p + 1; i <= N; i += (i & -i)) {
      v[i - 1] += val;
    }
  }
  T query(int p) {
    T sum = 0;
    for(int i = p + 1; i >= 1; i -= (i & -i)) {
      sum += v[i - 1];
    }
    return sum;
  }
  T range(int L, int R) {
    return query(R) - query(L - 1);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<vector<int>> ga(N);
    for (int i = 1; i < N; ++i) {
      int P;
      cin >> P;
      P --;
      ga[P].push_back(i);
    }
    vector<vector<int>> gb(N);
    vector<int> par(N, -1);
    for(int i = 1; i < N; ++i) {
      int P;
      cin >> P;
      P --;
      gb[P].push_back(i);
      par[i] = P;
    }
    vector<vector<int>> jump(N, vector<int> (21, -1));
    for (int i = 0; i < N; ++i) {
      jump[i][0] = par[i];
    }
    for (int j = 0; j < 20; ++j) {
      for (int i = 0; i < N; ++i) {
        if (jump[i][j] != -1) {
          jump[i][j + 1] = jump[jump[i][j]][j];
        } 
      }
    }
    vector<int> in(N);
    vector<int> out(N);
    vector<int> Oi(N);
    vector<int> Ou(N);
    int dfn = 0;
    int dfs_clock = 0;
    auto dfs_1 = [&] (auto &&f, int X) -> void {
      in[X] = dfn ++;
      Oi[X] = dfs_clock ++;
      for (int Y : gb[X]) {
        f(f, Y);
      }
      out[X] = dfn;
      Ou[X] = dfs_clock ++;
    };
    dfs_1(dfs_1, 0);
    FenwickTree<int> fw(N);
    FenwickTree<int> up(N + N);
    vector<bool> Put(N);
    vector<int> Kill(N, -1);
    set<int> S;
    int Ans = 0;
    auto dfs_2 = [&] (auto &&f, int X) -> void {
      if (fw.range(in[X], out[X] - 1) >= 1) {
        Put[X] = false;
      } else {
        S.insert(X);
        Put[X] = true;
        int tmp = up.query(Oi[X]);
        if (tmp >= 1) {
          int Y = X;
          for (int i = 20; i >= 0; --i) {
            int Z = jump[Y][i];
            if (Z != -1 && tmp == up.query(Oi[Z])) {
              Y = Z;
            }  
          }
          Kill[X] = Y;
          S.erase(Y);
          fw.add(in[Y], -1);
          up.add(Oi[Y], -1);
          up.add(Ou[Y], 1);
        }
        up.add(Oi[X], 1);
        up.add(Ou[X], -1);
        fw.add(in[X], 1);
        S.insert(X);
      }
      Ans = max(Ans, (int)S.size());
      for (int Y : ga[X]) {
        f(f, Y); 
      }
      if (Put[X]) {
        S.erase(X);
        up.add(Oi[X], -1);
        up.add(Ou[X], 1);
        fw.add(in[X], -1);
      }
      if (Kill[X] != -1) {
        int Y = Kill[X];
        S.insert(Y);
        fw.add(in[Y], 1);
        up.add(Oi[Y], 1);
        up.add(Ou[Y], -1);
      }
    };
    dfs_2(dfs_2, 0);
    cout << Ans << '\n';
  }
}
/*
1
4
1 2 3
1 2 3

1
6
1 1 1 1 2
1 2 1 2 2
 */
