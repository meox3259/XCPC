#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<long long> B(N);
    for (int i = 1; i < N; ++i) {
      B[i] = abs(A[i - 1] - A[i]);
    }
    vector<vector<long long>> f(N + 1, vector<long long> (21));
    for (int i = 1; i < N; ++i) {
      f[i][0] = B[i];
    }
    vector<int> lg(N + 1);
    for (int i = 1; i <= N; ++i) {
      lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (int j = 1; j <= 20; ++j) {
      for (int i = 0; i < N - (1 << j) + 1; ++i) {
        f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
      } 
    }
    auto query = [&] (int L, int R) -> long long {
      int x = lg[R - L + 1] - 1;
      return __gcd(f[L][x], f[R - (1 << x) + 1][x]);
    };
    int L = 0;
    int R = N;
    while (R - L > 1) {
      int Mid = (L + R) / 2;
      bool ok = false;
      for (int i = Mid; i < N; ++i) {
        if (query(i - Mid + 1, i) >= 2) {
          ok = true;
          break;
        }
      }
      if (ok) {
        L = Mid;
      } else {
        R = Mid;
      }
    }
    cout << L + 1 << '\n';
  }
}
