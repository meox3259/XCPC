#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  auto level = [&] (long long x) -> int {
    int cnt = 0;
    while (x) {
      cnt ++;
      x /= 2;
    }
    return cnt;
  };
  vector<long long> s1(100);
  vector<long long> s2(100);
  while (q --> 0) {
    int type;
    cin >> type;
    if (type == 1) {
      long long x, k;
      cin >> x >> k;
      int m = level(x) - 1;
      s1[m] += (1ll << m) - k;
      s1[m] %= (1ll << m);
      s1[m] += (1ll << m);
      s1[m] %= (1ll << m);
      s2[m] += (1ll << m) + k;
      s2[m] %= (1ll << m);
      s2[m] += (1ll << m);
      s2[m] %= (1ll << m);
    }
    if (type == 2) {
      long long x, k;
      cin >> x >> k;
      int m = level(x) - 1;
      s2[m] += (1ll << m) + k;
      s2[m] %= (1ll << m);
      s2[m] += (1ll << m);
      s2[m] %= (1ll << m);
    }
    if (type == 3) {
      long long x;
      vector<long long> ans;
      cin >> x;
      int m = level(x);
      for (int i = m - 1; i >= 0; --i) {
        ans.push_back(x);
        long long z = x - (1ll << i);
        z += s2[i];
        z %= (1ll << i);
        z += (1ll << i);
        z /= 2;
        if (i >= 1) {
          z -= (1ll << i - 1);
          z += s1[i - 1];
          z %= (1ll << i - 1);
          z += (1ll << i - 1);
        }
        x = z;
      }
      for (int i = 0; i < m; ++i) {
        cout << ans[i] << " \n"[i == m - 1];
      }
    }
  }
}
