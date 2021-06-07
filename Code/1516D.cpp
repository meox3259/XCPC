#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> P(100001);
  iota(P.begin(), P.end(), 0);
  for (int i = 2; i <= 100000; ++i) {
    if (P[i] == i) {
      for (int j = i + i; j <= 100000; j += i) {
        P[j] = i;
      }
    }
  }
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<vector<int>> fac(N);
  vector<vector<int>> Pos(100001);
  for (int i = 0; i < N; ++i) {
    while (A[i] != 1) {
      int X = P[A[i]];
      fac[i].push_back(X);
      Pos[X].push_back(i);
      while (A[i] % X == 0) {
        A[i] /= X;
      }
    }
  }
  vector<int> R(N, N);
  for (int i = 0; i <= 100000; ++i) {
    for (int j = 0; j + 1 < Pos[i].size(); ++j) {
      R[Pos[i][j]] = min(R[Pos[i][j]], Pos[i][j + 1]);
    }
  }
  for (int i = N - 1; i >= 1; --i) {
    R[i - 1] = min(R[i - 1], R[i]);
  }
  vector<vector<int>> jump(N + 1, vector<int> (20));
  for (int i = 0; i < N; ++i) {
    jump[i][0] = R[i];
  }
  for (int i = 0; i < 20; ++i) {
    jump[N][i] = N;
  }
  for (int j = 0; j < 19; ++j) {
    for (int i = 0; i < N; ++i) {
      jump[i][j + 1] = jump[jump[i][j]][j];
    }
  }
  while (Q --> 0) {
    int L, R;
    cin >> L >> R;
    L --;
    R --;
    int Ans = 0;
    for (int i = 19; i >= 0; --i) {
      if (jump[L][i] <= R) {
        Ans ^= (1 << i);
        L = jump[L][i];
      }
    }
    cout << Ans + 1 << '\n';
  }
}
