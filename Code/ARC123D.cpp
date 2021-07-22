#include <bits/stdc++.h>
using namespace std;
const long long INF = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  long long L = -1e13;
  long long R = 1e13;
  auto calc = [&] (long long X) -> long long {
    long long ret = 0;
    long long Y = A[0] - X; 
    ret += abs(X) + abs(Y);
    for (int i = 1; i < N; ++i) {
      if (X + Y <= A[i]) {
        Y += A[i] - X - Y;
      } else {
        X -= X + Y - A[i]; 
      }
      ret += abs(X) + abs(Y);
    }
    return ret;
  };
  while (R - L > 2) {
    long long LMid = (L + L + R) / 3;
    long long RMid = (L + R + R) / 3;
    if (calc(LMid) > calc(RMid)) {
      L = LMid;
    } else {
      R = RMid;
    }
  }
  long long Ans = INF;
  for (long long i = L; i <= R; ++i) {
    Ans = min(Ans, calc(i));
  }
  cout << Ans << '\n';
}
