#include <bits/stdc++.h>
using namespace std;
int main() {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  vector<int> b(n);
  iota(b.begin(), b.end(), 0);
  vector<int> ans(n, -1);
  auto query = [&] (int i, int j) -> char {
    cout << '?' << ' ' << i + 1 << ' ' << j + 1 << endl;
    char ret;
    cin >> ret;
    return ret;
  };
  auto solve = [&] (auto &&f, vector<int> a, vector<int> b) -> void {
    if (a.empty() && b.empty()) {
      return;
    }
    int n = a.size();
    int p = mt() % n;
    int q = -1;
    for (int i = 0; i < n; ++i) {
      if (query(a[p], b[i]) == '=') {
        q = i;
        break;
      }
    }
    ans[a[p]] = b[q];
    vector<int> la;
    vector<int> lb;
    vector<int> ra;
    vector<int> rb;
    for (int i = 0; i < n; ++i) {
      char c1 = query(a[i], b[q]);
      if (c1 == '<') {
        la.push_back(a[i]);
      } else if (c1 == '>') {
        ra.push_back(a[i]);
      }
      char c2 = query(a[p], b[i]);
      if (c2 == '<') {
        rb.push_back(b[i]);
      } else if (c2 == '>') {
        lb.push_back(b[i]);
      }
    }
    f(f, la, lb);
    f(f, ra, rb);
  };
  solve(solve, a, b);
  cout << '!';
  for (int i = 0; i < n; ++i) {
    cout << ' ' << ans[i] + 1;
  }
  cout << endl;
}
