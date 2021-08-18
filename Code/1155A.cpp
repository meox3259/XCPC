#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> p(26, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = s[i] - 'a' + 1; j < 26; ++j) {
      if (p[j] != -1) {
        cout << "YES" << '\n';
        cout << p[j] + 1 << ' ' << i + 1 << '\n';
        exit(0);
      }
    }
    p[s[i] - 'a'] = i;
  }
  cout << "NO" << '\n';
}
