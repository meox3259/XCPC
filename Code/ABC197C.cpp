#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  long long Ans = numeric_limits<long long> :: max();
  for (int S = 0; S < 1 << N; ++S) {
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
      C[i] = (S >> i & 1);
    }
    long long SS = 0;
    long long Xor = 0;
    for (int i = 0; i < N; ++i) {
      if (i == 0 || C[i] != C[i - 1]) {
        Xor ^= SS; 
        SS = 0;
      }
      SS |= A[i];
    } 
    Xor ^= SS;
    Ans = min(Ans, Xor);
  }
  cout << Ans << '\n';
}
