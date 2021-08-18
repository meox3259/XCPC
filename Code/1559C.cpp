#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == 0 && a[i + 1] == 1) {
        ok = true; 
        for (int j = 0; j <= i; ++j) {
          cout << j + 1 << ' ';
        }
        cout << n + 1 << ' ';
        for (int j = i + 1; j < n; ++j) {
          cout << j + 1 << ' ';
        }
        cout << '\n';
        break;
      }
    }
    if (ok) {
      continue;
    }
    if (a[n - 1] == 0) {
      for (int i = 0; i <= n; ++i) {
        cout << i + 1 << " \n"[i == n];
      }
      continue;
    }
    if (a[0] == 1) {
      cout << n + 1 << ' ';
      for (int i = 0; i < n; ++i) {
        cout << i + 1 << " \n"[i == n - 1];
      }
      continue;
    }
    cout << -1 << '\n';
  }
}
