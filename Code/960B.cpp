#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int k = k1 + k2;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = abs(a[i] - b[i]);
  }
  long long s = accumulate(c.begin(), c.end(), 0ll);
  for (int i = 0; i < min((long long)k, s); ++i) {
    sort(c.begin(), c.end());   
    c.back() --;
  }
  k -= min((long long)k, s);
  if (k > 0 && (k & 1)) {
    c[0] ++;
  }
  long long ans = 0;
  for (auto v : c) {
    ans += v * v;
  }
  cout << ans << '\n';
}
