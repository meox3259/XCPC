#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  ans += (min(N, 999999LL) - min(1000LL - 1, N));
  ans += (min(N, 999999999LL) - min(1000000LL - 1, N)) * 2;
  ans += (min(N, 999999999999LL) - min(1000000000LL - 1, N)) * 3;
  ans += (min(N, 999999999999999LL) - min(1000000000000LL - 1, N)) * 4;
  ans += (N == 1000000000000000LL) * 5;
  cout << ans << '\n';
  return 0;
}
