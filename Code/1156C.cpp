#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, z;
  cin >> n >> z;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  int l = -1;
  int r = n / 2 + 1;
  while (r - l > 1) {
    int mid = l + r >> 1;
    bool ok = true;
    for (int i = 0, j = mid; i < mid; ++i) {
      while (j < n && x[j] - x[i] < z) {
        j ++;
      } 
      if (j == n) {
        ok = false;
        break;
      }
      j ++;
    }
    if (ok) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << '\n';
}
