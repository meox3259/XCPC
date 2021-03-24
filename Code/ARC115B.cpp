#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<long long>> C(N, vector<long long> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> C[i][j];
    }
  }
  if (N == 1) {
    cout << "Yes" << '\n';
    cout << C[0][0] << '\n';
    cout << 0 << '\n';
    exit(0);
  }
  long long S = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      S += C[i][j];
    }
  }
  if (S % N != 0) {
    cout << "No" << '\n';
    exit(0);
  }
  vector<long long> A(N);
  vector<long long> B(N);
  long long Min = 1e18;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      Min = min(Min, C[i][j]); 
    }
  }
  for (int i = 0; i < N; ++i) {
    bool ok = false;
    for (int j = 0; j < N; ++j) {
      if (C[i][j] == Min) {
        ok = true;
        A[i] = C[i][j]; 
        for (int k = 0; k < N; ++k) {
          B[k] = C[i][k] - A[i];
        }
        for (int k = 0; k < N; ++k) {
          A[k] = C[k][0] - B[0];
        }
        break;
      }
    }
    if (ok) {
      break;
    }
  }
  if (*min_element(A.begin(), A.end()) < 0 || *min_element(B.begin(), B.end()) < 0) {
    cout << "No" << '\n';
    exit(0);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (A[i] + B[j] != C[i][j]) {
        cout << "No" << '\n';
        exit(0);
      }
    }
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < N; ++i) {
    cout << A[i] << " \n"[i == N - 1];
  }
  for (int i = 0; i < N; ++i) {
    cout << B[i] << " \n"[i == N - 1];
  }
}
