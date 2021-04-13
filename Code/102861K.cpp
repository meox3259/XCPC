#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int> (N + 1));
  vector<int> deg(N);
  for (int i = 0; i < M; ++i) {
    int X, Y;
    cin >> X >> Y;
    X --;
    Y --;
    deg[X] ++;
    deg[Y] ++;
    A[X][Y] = 1;
    A[Y][X] = 1;
  }
  for (int i = 0; i < N; ++i) {
    if (deg[i] % 2 == 0) {
      A[i][N] = 1;
    } else {
      A[i][i] = 1;
    }
  }
  int rnk = 0;
  for (int j = 0; j < N; ++j) {
    int P = -1;
    for (int i = rnk; i < N; ++i) {
      if (A[i][j] > 0) {
        P = i;
        break;
      }
    }
    if (P == -1) {
      continue;
    }
    swap(A[rnk], A[P]);
    for (int i = 0; i < N; ++i) {
      if (i != rnk && A[i][j]) {
        for (int k = 0; k <= N; ++k) {
          A[i][k] ^= A[rnk][k];
        }
      }
    }
    rnk ++;
  }
  for (int i = rnk; i < N; ++i) {
    if (A[i][N] > 0) {
      cout << 'N' << '\n';
      exit(0);
    }
  }
  cout << 'Y' << '\n';
}
