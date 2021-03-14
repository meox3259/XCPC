#include <bits/stdc++.h>
using namespace std;
const int P[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int main() {
  long long A, B;
  cin >> A >> B;
  unordered_map<long long, int> mp;
  for (long long i = A; i <= B; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (i % P[j] == 0) {
        mp[i] |= 1 << j;
      }
    }
  }
  vector<long long> f(1 << 20);
  f[0] = 1;
  for (long long i = A; i <= B; ++i) {
    int S0 = mp[i];
    vector<long long> tmp(f);
    for (int S = 0; S < 1 << 20; ++S) {
      if (!(S & S0)) {
        f[S | S0] += f[S];
      }
    }
  }
  long long ans = 0;
  for (int S = 0; S < 1 << 20; ++S) {
    ans += f[S];
  }
  cout << ans << '\n';
  return 0;
}
