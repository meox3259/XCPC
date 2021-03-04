#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --) {
    int n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    bool ok = false;
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        for (int c = 0; c < 2; ++c) {
          for (int d = 0; d < 2; ++d) {
            if ((0 <= U - a - b && U - a - b <= n - 2) && (0 <= R - b - c && R - b - c <= n - 2)
                && (0 <= D - d - c && D - d - c <= n - 2) && (0 <= L - a - d && L - a - d <= n - 2)) {
              ok = true;
            }
          }
        }
      } 
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
