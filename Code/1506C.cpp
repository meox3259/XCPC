#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    string A, B;
    cin >> A >> B;
    int N = A.size();
    int M = B.size();
    int Ans = N + M;
    for (int L = 0; L <= min(N, M); ++L) {
      for (int i = 0; i + L - 1 < N; ++i) {
        for (int j = 0; j + L - 1 < M; ++j) {
          bool ok = true;
          for (int k = 0; k < L; ++k) {
            if (A[i + k] != B[j + k]) {
              ok = false;
              break;
            }
          } 
          if (ok) {
            Ans = min(Ans, N + M - L - L); 
          }
        }
      } 
    }
    cout << Ans << '\n';
  }
}
