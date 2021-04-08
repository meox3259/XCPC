#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, D;
  while (cin >> M >> N >> D) {
    if (N == 0 && M == 0 && D == 0) {
      break;
    }
    vector<vector<int>> S(N, vector<int> (M));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> S[i][j];
      }
    }
    int K = N * M;
    vector<vector<int>> A(K, vector<int> (K + 1));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        A[i * M + j][i * M + j] = 1;
        A[i * M + j][K] = S[i][j] ^ 1;
        for (int X = 0; X < N; ++X) {
          for (int Y = 0; Y < M; ++Y) {
            if (abs(i - X) + abs(j - Y) == D) {
              A[i * M + j][X * M + Y] = 1; 
            }
          }
        } 
      }
    }
    int rnk = 0;
    for (int j = 0; j < K; ++j) {
      int P = -1;
      for (int i = rnk; i < K; ++i) {
        if (A[i][j] > 0) {
          P = i;
          break;
        }
      }
      if (P == -1) {
        continue;
      }
      swap(A[rnk], A[P]);
      for (int i = 0; i < K; ++i) {
        if (i != rnk && A[i][j] > 0) {
          for (int k = 0; k <= K; ++k) {
            A[i][k] ^= A[rnk][k];
          }
        }
      }
      rnk ++;
    }
    bool ok = true;
    for (int i = rnk; i < K; ++i) {
      if (A[i][K] > 0) {
        ok = false;
      }
    }
    if (ok) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}
