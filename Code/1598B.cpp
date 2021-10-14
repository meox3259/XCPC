#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (5));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> a[i][j];
      }
    }
    if (n & 1) {
      cout << "NO\n";
      continue;
    }
    bool ok = false;
    for (int i = 0; i < 5; ++i) {
      for (int j = i + 1; j < 5; ++j) {
        int c1 = 0;
        int c2 = 0;
        int c12 = 0;
        for (int k = 0; k < n; ++k) {
          if (a[k][i] == 1 && a[k][j] == 1) {
            c12++; 
          } else if (a[k][i] == 1) {
            c1++;
          } else if (a[k][j] == 1) {
            c2++;
          }
        } 
        int m = n / 2;
        if (c1 <= m && c2 <= m && m - c1 + m - c2 <= c12) {
          ok = true;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
