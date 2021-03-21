#include <bits/stdc++.h>
using namespace std;
const long long Inf = numeric_limits<long long> :: max() / 2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<long long> A(N);
  vector<int> t(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> t[i];
  }
  long long L = Inf;
  long long R = -Inf;
  long long Add = 0;
  for (int i = 0; i < N; ++i) {
    if (t[i] == 1) {
      Add += A[i];
      L += A[i];
      R += A[i];
    }
    if (t[i] == 2) {
      L = max(L, A[i]);
      R = max(R, A[i]);
    }
    if (t[i] == 3) {
      L = min(L, A[i]);
      R = min(R, A[i]);
    }
  }
  int Q;
  cin >> Q;
  while (Q --> 0) {
    long long X;
    cin >> X;
    cout << min(max(X + Add, R), L) << '\n';
  }
}
