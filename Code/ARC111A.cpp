#include <bits/stdc++.h>
using namespace std;
long long Pow(long long x, long long t, long long P) {
  long long ret = 1;
  for (; t; t >>= 1, x = x * x % P) {
    if (t & 1) {
      ret = ret * x % P;
    }
  }
  return ret;
}
int main() {
  long long N, M;
  cin >> N >> M;
  cout << (Pow(10, N, M * M) / M % M) << '\n';
  return 0;
}
