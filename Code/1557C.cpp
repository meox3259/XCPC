#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long modpow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) {
      ret = ret * x % mod;
    }
  }
  return ret;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long s = 1;
    long long ans = 0;
    for (int i = k - 1; i >= 0; --i) {
      if (n % 2 == 0) {
        ans += s * modpow(2, 1ll * n * i);
        ans %= mod;
        s *= modpow(2, n - 1) - 1;
        s %= mod;
      } else {
        s *= (modpow(2, n - 1) + 1); 
        s %= mod;
      }
    }
    ans += s;
    ans %= mod;
    cout << ans << '\n';
  }
}
