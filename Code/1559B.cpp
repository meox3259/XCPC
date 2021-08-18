#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        p = i;
        break;
      }
    }
    if (p == -1) {
      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          cout << 'B';
        } else {
          cout << 'R';
        }
      }
      cout << '\n';
      continue;
    }
    for (int i = p; i < n; ++i) {
      if (s[i] == '?') {
        s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
      }
    }
    for (int i = p - 1; i >= 0; --i) {
      if (s[i] == '?') {
        s[i] = (s[i + 1] == 'B' ? 'R' : 'B');
      } 
    }
    cout << s << '\n';
  }
}
