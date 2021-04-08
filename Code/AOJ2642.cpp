#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long P, Q;
  cin >> N >> P >> Q;
  vector<long long> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }
  vector<long long> D(N);
  for (int i = 0; i < N; ++i) {
    D[i] = C[i] + P * i;
  }
  sort(D.begin(), D.end());
  long long Sum = accumulate(C.begin(), C.end(), 0LL);
  long long Ans = Sum;
  for (int j = 0; j < N; ++j) {
    Sum -= D[j]; 
    Sum += (Q + j * 2) * P;
    Ans = max(Ans, Sum);
  }
  cout << Ans << '\n';
}
