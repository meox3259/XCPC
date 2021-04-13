#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<double>> P(N, vector<double> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> P[i][j];
    }
  }
  vector<vector<double>> A(N, vector<double> (N));
  A[0][0] = 1;
  auto Mul = [&] (const vector<vector<double>> &A, const vector<vector<double>> &B) -> vector<vector<double>> {
    vector<vector<double>> ret(N, vector<double> (N));
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          ret[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return ret;
  };
  for (; M; M >>= 1, P = Mul(P, P)) {
    if (M & 1) {
      A = Mul(A, P);
    }
  }
  cout << fixed << setprecision(10);
  for (int i = 0; i < N; ++i) {
    cout << A[0][i] << '\n';
  }
}
