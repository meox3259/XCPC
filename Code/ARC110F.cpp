#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[p[i]] = i;
  }
  vector<int> ans;
  auto move = [&] (int i) -> void {
    ans.push_back(i);
    swap(pos[p[i]], pos[p[(i + p[i]) % n]]);
    swap(p[i], p[(i + p[i]) % n]);
  };
  for (int i = n - 1; i >= 0; --i) {
    while (p[i] != n - 1 - i) {
      move(i);
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    while (pos[1] != n - 1) {
      move(pos[1]); 
    } 
    move(i);
  }
  move(0);
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << '\n';
  }
  return 0;
}
