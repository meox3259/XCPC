#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int M = 1000000005;
const int P = 998244353;
class sgt {
 private:
  vector<int> sum;
  vector<int> add;
  vector<int> mul;
  vector<int> lc;
  vector<int> rc;
  int Pool;
 public:
  sgt() {}
  sgt(int N) : lc(N * 40), rc(N * 40), sum(N * 40), add(N * 40), mul(N * 40, 1) { Pool = 0; }
  void pushdown(int X, int L, int R) {
    if (!lc[X]) {
      lc[X] = ++Pool;
    }
    if (!rc[X]) {
      rc[X] = ++Pool;
    }
    int mid = L + R >> 1;
    if (mul[X] != 1) {
      mul[lc[X]] = 1LL * mul[lc[X]] * mul[X] % P;
      mul[rc[X]] = 1LL * mul[rc[X]] * mul[X] % P;
      sum[lc[X]] = 1LL * sum[lc[X]] * mul[X] % P;
      sum[rc[X]] = 1LL * sum[rc[X]] * mul[X] % P;
      add[lc[X]] = 1LL * add[lc[X]] * mul[X] % P;
      add[rc[X]] = 1LL * add[rc[X]] * mul[X] % P;
      mul[X] = 1;
    }
    if (add[X] != 0) {
      add[lc[X]] += add[X];
      add[lc[X]] %= P;
      add[rc[X]] += add[X];
      add[rc[X]] %= P;
      sum[lc[X]] += 1LL * add[X] * (mid - L + 1) % P;
      sum[rc[X]] += 1LL * add[X] * (R - mid) % P;
      sum[lc[X]] %= P;
      sum[rc[X]] %= P;
      add[X] = 0;
    }
  }
  void Add(int L, int R, int &X, int A, int B, int V) {
    if (L > B || R < A) {
      return;
    }
    if (X == 0) {
      X = ++Pool;
    }
    if (L >= A && R <= B) {
      sum[X] += 1LL * (R - L + 1) * V % P;
      sum[X] %= P;
      add[X] += V;
      add[X] %= P;
      return;
    }
    pushdown(X, L, R);
    int mid = L + R >> 1;
    Add(L, mid, lc[X], A, B, V);
    Add(mid + 1, R, rc[X], A, B, V);
    sum[X] = (sum[lc[X]] + sum[rc[X]]) % P;
  }
  void Mul(int L, int R, int &X, int A, int B, int V) {
    if (L > B || R < A) {
      return;
    } 
    if (X == 0) {
      X = ++Pool;
    }
    if (L >= A && R <= B) {
      sum[X] = 1LL * sum[X] * V % P;
      mul[X] = 1LL * mul[X] * V % P;
      add[X] = 1LL * add[X] * V % P;
      return;
    }
    pushdown(X, L, R);
    int mid = L + R >> 1;
    Mul(L, mid, lc[X], A, B, V);
    Mul(mid + 1, R, rc[X], A, B, V);
    sum[X] = (sum[lc[X]] + sum[rc[X]]) % P;
  }
  int S() {
    return sum[1]; 
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int Root = 0;
  sgt sgt(N + N + 5); 
  sgt.Add(1, M, Root, 1, A[0], 1);
  for (int i = 1; i < N; ++i) {
    int S = sgt.S(); 
    sgt.Mul(1, M, Root, 1, M, P - 1);
    sgt.Add(1, M, Root, 1, A[i], S);
    sgt.Mul(1, M, Root, A[i] + 1, M, 0);
  }
  cout << sgt.S() << '\n';
}
