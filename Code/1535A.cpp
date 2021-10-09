#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> s(4);
    for (int i = 0; i < 4; ++i) {
      cin >> s[i]; 
    }
    vector<int> t(s);
    sort(t.begin(), t.end());
    int a = max(s[0], s[1]);
    int b = max(s[2], s[3]);
    if (a < b) {
      swap(a, b);
    }
    if (t[3] == a && t[2] == b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
