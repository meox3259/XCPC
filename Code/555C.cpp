#include <bits/stdc++.h>
using namespace std;
class sgt {
 private:
  vector<int> Max;
  vector<int> Lc;
  vector<int> Rc;
  int Pool = 0;
 public:
  sgt() {}
  sgt(int N) : Lc(N * 50), Rc(N * 50), Max(N * 50, -1) {}
  void update(int L, int R, int &X, int A, int B, int V) {
    if (L > B || R < A) {
      return;
    }
    if (X == 0) {
      X = ++Pool;
    }
    if (L >= A && R <= B) {
      Max[X] = max(Max[X], V);
      return;
    }
    int Mid = L + R >> 1;
    update(L, Mid, Lc[X], A, B, V);
    update(Mid + 1, R, Rc[X], A, B, V);
  }
  int query(int L, int R, int X, int P) {
    if (X == 0) {
      return -1;
    }
    if (L == R) {
      return Max[X];
    }
    int Mid = L + R >> 1;
    if (P <= Mid) {
      return max(Max[X], query(L, Mid, Lc[X], P));
    } else {
      return max(Max[X], query(Mid + 1, R, Rc[X], P));
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  sgt Row(Q);
  sgt Col(Q);
  int R0 = 0;
  int R1 = 0;
  map<pair<int, int>, bool> vis;
  while (Q --> 0) {
    int X, Y;
    char Dir;
    cin >> X >> Y >> Dir;
    X --;
    Y --;
    if (vis.find({X, Y}) != vis.end()) {
      cout << 0 << '\n';
      continue;
    }
    vis[{X, Y}] = true;
    if (Dir == 'U') {
      int U = Col.query(0, N - 1, R0, X);
      cout << Y - U << '\n';
      Row.update(0, N - 1, R1, U + 1, Y, X);
    }
    if (Dir == 'L') {
      int L = Row.query(0, N - 1, R1, Y); 
      cout << X - L << '\n';
      Col.update(0, N - 1, R0, L + 1, X, Y);
    }
  }
}
