#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, d;
  cin >> x >> d;
  long long s = 1;
  vector<long long> ans;
  while (x > 0) {
    long long b = 1;
    while ((1ll << (b + 1)) - 1 <= x) {
      b ++;
    }
    x -= (1ll << b) - 1;
    for (int i = 0; i < b; ++i) {
      ans.push_back(s);
    }
    s += d;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
}
