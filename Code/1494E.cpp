#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  map<pair<int, int>, int> mp;
  map<tuple<int, int, int>, int> tot;
  int one = 0;
  int two = 0;
  int cir = 0;
  while (m --) {
    char opt;
    cin >> opt;
    if (opt == '+') {
      int u, v;
      char c;
      cin >> u >> v >> c;
      u --;
      v --;
      int a = c - 'a';
      mp[make_pair(u, v)] = a;
      if (mp.find(make_pair(v, u)) != mp.end()) {
        int b = mp[make_pair(v, u)];
        if (a == b) {
          one ++; 
        } else {
          two ++;
        }
      }
    }
    if (opt == '-') {
      int u, v;
      cin >> u >> v;
      u --;
      v --;
      int a = mp[{u, v}];
      if (mp.find(make_pair(v, u)) != mp.end()) {
        int b = mp[{v, u}];
        if (a == b) {
          one --;
        } else {
          two --;
        }
      }
      mp.erase(make_pair(u, v));
    }
    if (opt == '?') {
      int k;
      cin >> k;
      if (k % 2 == 1) {
        if (one || two) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      } else {
        if (one) {
          cout << "YES" << '\n';
        } else {
          cout << "NO" << '\n';
        }
      }
    }
  }
  return 0;
}
