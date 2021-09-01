#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ori(n);
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> ori[i] >> d[i]; 
  }
  int dir = 1;
  int x = 0;
  int y = 0;
  int lx = 0;
  int rx = 0;
  int ly = 0;
  int ry = 0;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (dir == 0) {
      ans.push_back(ry - y + 1);
      y = ry + 1;
      ry ++;
    }
    if (dir == 1) {
      ans.push_back(rx - x + 1);
      x = rx + 1;
      rx ++;
    }
    if (dir == 2) {
      ans.push_back(y - ly + 1);
      y = ly - 1;
      ly --;
    }
    if (dir == 3) {
      ans.push_back(x - lx + 1);
      x = lx - 1;
      lx --;
    }
    dir = (dir + d[i] + 4) % 4;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
