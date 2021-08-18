#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '8' && n - i >= 11) {
      cnt ++;
    }
  }
  int d = (n - 11) / 2;
  if (cnt <= d) {
    cout << "NO" << '\n';
    exit(0);
  } else {
    cout << "YES" << '\n';
  }
}
