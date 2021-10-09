#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = max(s.size(), t.size()) * 2 + 10; 
  map<pair<int, int>, int> mp;
  map<int, pair<int, int>> pm;
  int tot = 0;
  auto solve = [&] (string s) -> vector<int> {
    vector<int> a;
    for (int i = 2; i < n; ++i) {
      a.push_back(-i);
    }
    for (char c : s) {
      if (c == 'C') {
        a.push_back(a.back());
      }
      if (c == 'D') {
        a.pop_back();
      }
      if (c == 'L') {
        if (a.back() < 0) {
          return {-1};
        }
        int x = a.back();
        a.pop_back();
        a.push_back(pm[x].first);
      }
      if (c == 'P') {
        int x = a.back();
        a.pop_back();
        int y = a.back();
        a.pop_back();
        if (mp.find({x, y}) == mp.end()) {
          pm[tot] = {x, y};
          mp[{x, y}] = tot++;
        }
        a.push_back(mp[{x, y}]);
      }
      if (c == 'R') {
        if (a.back() < 0) {
          return {-1};
        }
        int x = a.back();
        a.pop_back();
        a.push_back(pm[x].second);
      }
      if (c == 'S') {
        int x = a.back();
        a.pop_back();
        int y = a.back();
        a.pop_back();
        a.push_back(x);
        a.push_back(y);
      }
      if (c == 'U') {
        if (a.back() < 0) {
          return {-1};
        } 
        int x = a.back();
        a.pop_back();
        a.push_back(pm[x].second);
        a.push_back(pm[x].first);
      }
    }
    return a;
  };
  if (solve(s) == solve(t)) {
    cout << "True\n";
  } else {
    cout << "False\n";
  }
}
