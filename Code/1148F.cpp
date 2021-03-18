#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> val(N);
  vector<long long> mask(N);
  for (int i = 0; i < N; ++i) {
    cin >> val[i] >> mask[i];
  }
  if (accumulate(val.begin(), val.end(), 0LL) < 0) {
    for (int i = 0; i < N; ++i) {
      val[i] = -val[i];
    }
  }
  long long ans = 0;
  for (int i = 61; i >= 0; --i) {
    long long S = 0;
    for (int j = 0; j < N; ++j) {
      if (mask[j] == (1LL << i)) {
        S += val[j]; 
      }
    }
    if (S > 0) {
      ans ^= 1LL << i;
      for (int j = 0; j < N; ++j) {
        if (mask[j] >> i & 1) {
          val[j] = -val[j];
        }
      }
    }
    for (int j = 0; j < N; ++j) {
      if (mask[j] >> i & 1) {
        mask[j] ^= 1LL << i;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
