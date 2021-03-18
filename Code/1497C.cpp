#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int N, K;
    cin >> N >> K;
    auto solve = [&] (int N) -> void {
      if (N % 4 == 0) {
        cout << N / 2 << ' ' << N / 4 << ' ' << N / 4 << '\n';
      }
      if (N % 4 == 1) {
        cout << (N - 1) / 2 << ' ' << (N - 1) / 2 << ' ' << 1 << '\n';
      }
      if (N % 4 == 2) {
        cout << (N - 2) / 2 << ' ' << (N - 2) / 2 << ' ' << 2 << '\n';
      }
      if (N % 4 == 3) {
        cout << (N - 3) / 2 + 1 << ' ' << (N - 3) / 2 + 1 << ' ' << 1 << '\n'; 
      }
    };
    for (int i = 0; i < K - 3; ++i) {
      cout << 1 << ' ';
    } 
    N -= (K - 3);
    solve(N);
  }
  return 0;
}
