#include <bits/stdc++.h>
using namespace std;
int main() {
  auto check = [&] (int h, int w, int i1, int j1, int i2, int j2) -> int {
    cout << '?' << ' ' << h << ' ' << w << ' ' << i1 + 1 << ' ' << j1 + 1 << ' ' << i2 + 1 << ' ' << j2 + 1 << endl;
    int x;
    cin >> x;
    return x;
  };
  int n, m;
  cin >> n >> m;
  int x = n;
  int k = n;
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    int cnt = 1;
    while (x % i == 0) {
      if (i == 2) {
        if (check(k / 2, m, 0, 0, k / 2, 0)) {
          k /= 2;
          cnt++;
        }
      } else {
        if (check(k / i * (i / 2), m, 0, 0, k / i * (i / 2), 0) && 
            check(k / i * (i / 2), m, 0, 0, k / i * (i / 2 + 1), 0)) {
          k /= i;
          cnt++;
        }
      }
      x /= i;
    }
    ans *= cnt;
  }
  x = m;
  k = m;
  for (int i = 2; i <= m; ++i) {
    int cnt = 1;
    while (x % i == 0) {
      if (i == 2) {
        if (check(n, k / 2, 0, 0, 0, k / 2)) {
          k /= 2;
          cnt++;
        }
      } else {
        if (check(n, k / i * (i / 2), 0, 0, 0, k / i * (i / 2)) && 
            check(n, k / i * (i / 2), 0, 0, 0, k / i * (i / 2 + 1))) {
          k /= i;
          cnt++;
        }
      }
      x /= i;
    }
    ans *= cnt;
  }
  cout << '!' << ' ' << ans << '\n';
}
