#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
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
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  long long S = 0;
  long long Ans = 0;
  for (int i = 0; i < N; ++i) {
    Ans += A[i] * A[i] % P;
    Ans %= P;
    Ans += A[i] * power(2, i) % P * S % P;
    Ans %= P;
    S += A[i] * power(power(2, i + 1), P - 2) % P;
    S %= P;
  } 
  cout << Ans << '\n';
}
