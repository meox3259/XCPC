#include <bits/stdc++.h>
using namespace std;
const int P = 1'000'000'007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
    }
    int K = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (S[i][j] == '#') {
          K ++; 
        }
      }
    }
    long long Ans = 1;
    for (int i = 0; i < K; ++i) {
      Ans = Ans * 2 % P;
    }
    if (K == N * M) {
      Ans = (Ans - 1 + P) % P;
    }
    cout << Ans << '\n';
  }
}
