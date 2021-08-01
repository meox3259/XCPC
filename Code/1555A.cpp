#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    long long N;
    cin >> N;
    long long Ans = numeric_limits<long long> :: max() / 2;
    for (long long i = 0; i <= 10; ++i) {
      for (long long j = 0; j <= 10; ++j) {
        long long X = N - i * 6 - j * 8;
        if (X >= 0) {
          Ans = min(Ans, (X + 9) / 10 * 25 + i * 15 + j * 20);
        } else {
          Ans = min(Ans, i * 15 + j * 20);
        }
      }
    }
    cout << Ans << '\n';
  }
}
