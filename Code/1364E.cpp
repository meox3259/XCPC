#include <bits/stdc++.h>
using namespace std;
int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
  auto ask = [&] (int i, int j) {
    cout << '?' << ' ' << i + 1 << ' ' << j + 1 << endl; 
    int ret;
    cin >> ret;
    return ret;
  };
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  random_shuffle(p.begin(), p.end());
  int a = p[0];
  int b = p[1];
  int val = ask(p[0], p[1]);
  for (int i = 2; i < n; ++i) {
    int nval = ask(a, p[i]);
    if (val > nval) {
      b = p[i]; 
      val = nval;
    } else if (val == nval) {
      a = p[i];
      val = ask(a, b);
    }
  }
  vector<int> ans(n);
  while (true) {
    int c = mt() % n;
    while (c == a || c == b) {
      c = mt() % n;
    }
    int x = ask(a, c);
    int y = ask(b, c);
    if (x != y) {
      if (x < y) {
        for (int i = 0; i < n; ++i) {
          if (i != a) {
            ans[i] = ask(i, a);
          }
        }
      } else {
        for (int i = 0; i < n; ++i) {
          if (i != b) {
            ans[i] = ask(i, b);
          }
        }
      }
      break;
    }
  }
  cout << '!';
  for (int i = 0; i < n; ++i) {
    cout << ' ' << ans[i];
  }
  cout << endl;
}
