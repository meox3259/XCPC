#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int> (m, 1));
  vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, 1)));
  long long ans = 0;
  int one = n * m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i < n - 1) {
        dp[i + 1][j][0] += dp[i][j][1];
      } 
      if (j < m - 1) {
        dp[i][j + 1][1] += dp[i][j][0];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += dp[i][j][0] + dp[i][j][1];
    }
  }
  auto flip = [&] (int x, int y) -> void {
    a[x][y] ^= 1; 
    if (a[x][y] == 0) {
      a[x][y] ^= 1;
      one--;
      int v1 = dp[x][y][0]; 
      int v2 = dp[x][y][1];
      int tx = x;
      int ty = y;
      int dx = 0;
      int dy = 1;
      int d = 0;
      while (tx < n && ty < m) {
        if (a[tx][ty] == 0) {
          break;
        }
        dp[tx][ty][d] -= v1;
        ans -= v1;
        tx += dx;
        ty += dy;
        swap(dx, dy);
        d ^= 1;
      }
      tx = x;
      ty = y;
      dx = 1;
      dy = 0;
      d = 1;
      while (tx < n && ty < m) {
        if (a[tx][ty] == 0) {
          break;
        }
        dp[tx][ty][d] -= v2;
        ans -= v2;
        tx += dx;
        ty += dy;
        swap(dx, dy);
        d ^= 1;
      }
      a[x][y] ^= 1;
    } else {
      one++;
      int v1 = 1 + (x > 0 ? dp[x - 1][y][1] : 0); 
      int v2 = 1 + (y > 0 ? dp[x][y - 1][0] : 0);
      int tx = x;
      int ty = y;
      int dx = 0;
      int dy = 1;
      int d = 0;
      while (tx < n && ty < m) {
        if (a[tx][ty] == 0) {
          break;
        }
        dp[tx][ty][d] += v1;
        ans += v1;
        tx += dx;
        ty += dy;
        swap(dx, dy);
        d ^= 1;
      }
      tx = x;
      ty = y;
      dx = 1;
      dy = 0;
      d = 1;
      while (tx < n && ty < m) {
        if (a[tx][ty] == 0) {
          break;
        }
        dp[tx][ty][d] += v2;
        ans += v2;
        tx += dx;
        ty += dy;
        swap(dx, dy);
        d ^= 1;
      }
    }
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    flip(x, y);
    cout << ans - one << '\n';
  }
}
