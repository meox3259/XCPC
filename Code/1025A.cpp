#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  if (N == 1) {
    cout << "Yes" << '\n';
    exit(0);
  }
  vector<int> cnt(26);
  for (char c : S) {
    cnt[c - 'a'] ++;
  }
  if (*max_element(cnt.begin(), cnt.end()) == 1) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }
}
