#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
long long power(long long x, long long t) {
  long long ret = 1;
  for (; t; t >>= 1, x = x * x % P) {
    if (t & 1) {
      ret = ret * x % P;
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> S(1 << 20);
  for (int i : A) {
    S[i] ++;
  }
  for (int j = 0; j < 20; ++j) {
    for (int i = (1 << 20) - 1; i >= 0; --i) {
      if (i >> j & 1) {
        S[i ^ (1 << j)] += S[i];
      }
    }
  }
  long long Ans = 0;
  for (int i = 0; i < 1 << 20; ++i) {
    if (__builtin_popcount(i) & 1) {
      Ans -= power(2, S[i]) - 1;
      Ans += P;
      Ans %= P;
    } else {
      Ans += power(2, S[i]) - 1;
      Ans %= P;
    }
  }
  cout << Ans << '\n';
}
