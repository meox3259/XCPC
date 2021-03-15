#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int> (N));
  int X = 0;
  for (int i = 0; i < N; i += 2) {
    for (int j = 0; j < N; j += 2) {
      A[i][j] = X;
      A[i][j + 1] = X + 1;
      A[i + 1][j] = X + 2;
      A[i + 1][j + 1] = X + 3;
      X += 4;
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << A[i][j] << " \n"[j == N - 1];
    }
  }
  return 0;
}
