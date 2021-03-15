#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int main() {
  int H, W;
  cin >> H >> W;
  vector<int> h(2);
  vector<int> w(2);
  for (int i = 0; i < 2; ++i) {
    cin >> h[i] >> w[i];
  }
  sort(h.begin(), h.end());
  sort(w.begin(), w.end());
  int D = h[1] - h[0] + w[1] - w[0];
  vector<long long> inv(H + W + 1);
  inv[1] = 1;
  for (int i = 2; i <= H + W; ++i) {
    inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
  }
  long long ans = 1;
  for (int i = 1; i < h[0]; ++i) {
    ans += inv[i + D];
    ans %= P;
  }
  for (int i = 1; i <= H - h[1]; ++i) {
    ans += inv[i + D];
    ans %= P;
  }
  for (int i = 1; i < w[0]; ++i) {
    ans += inv[i + D];
    ans %= P;
  }
  for (int i = 1; i <= W - w[1]; ++i) {
    ans += inv[i + D];
    ans %= P;
  }
  cout << ans << '\n';
  return 0;
}
