#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<long long> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> C[i];
  }
  vector<int> id(N);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&] (int i, int j) {
    return A[i] < A[j];
  });
  long long Ans = accumulate(C.begin(), C.end(), 0LL);
  long long last = A[id[0]] + C[id[0]];
  for (int i = 1; i < N; ++i) {
    Ans += max(0LL, A[id[i]] - last);
    last = max(last, A[id[i]] + C[id[i]]);
  }
  cout << Ans << '\n';
}
