#include <bits/stdc++.h>
using namespace std;
long long Mul(long long A, long long B, long long P) {
    return ((A * B - (long long)((long double)A / P * B + 1e-3) * P) % P + P) % P;
}
long long power(long long X, long long Y, long long P) {
  long long ret = 1; 
  for (; Y; Y >>= 1, X = Mul(X, X, P)) {
    if (Y & 1) {
      ret = Mul(ret, X, P);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T --> 0) {
    long long A, P;
    cin >> A >> P;
    if (power(A, (P - 1) / 2, P) == 1) {
      cout << 0 << '\n'; 
    } else{
      cout << 1 << '\n';
    }
  }
}
