#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --) {
    string s;
    cin >> s;
    bool ok = false;
    for (int A = 0; A < 2; ++A) {
      for (int B = 0; B < 2; ++B) {
        for (int C = 0; C < 2; ++C) {
          int pre = 0; 
          bool f = true;
          for (char c : s) {
            if (c == 'A') {
              if (A == 0) {
                pre ++;
              } else {
                pre --;
              }
            }
            if (c == 'B') {
              if (B == 0) {
                pre ++;
              } else {
                pre --;
              }
            }
            if (c == 'C') {
              if (C == 0) {
                pre ++;
              } else {
                pre --;
              }
            }
            if (pre < 0) {
              f = false;
            }
          }
          if (pre != 0) {
            f = false;
          }
          if (f) {
            ok = true;
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
