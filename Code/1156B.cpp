#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T --> 0) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    for (char c : s) {
      cnt[c - 'a'] ++;
    }
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < 26; ++i) {
      if (i & 1) {
        s1 += string(cnt[i], (char)(i + 'a'));
      } else {
        s2 += string(cnt[i], (char)(i + 'a'));
      }
    }
    if (s1.empty() || s2.empty()) {
      cout << s1 + s2 << '\n';
    } else if (abs(s1.back() - s2.front()) > 1) {
      cout << s1 + s2 << '\n';
    } else if (abs(s1.front() - s2.back()) > 1) {
      cout << s2 + s1 << '\n';
    } else {
      cout << "No answer" << '\n';
    }
  }
}
